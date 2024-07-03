/*
 * Copyright (c) 2015 Universita' degli Studi di Napoli "Federico II"
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Pasquale Imputato <p.imputato@gmail.com>
 * Author: Stefano Avallone <stefano.avallone@unina.it>
 */

#include "ns3/applications-module.h"
#include "ns3/core-module.h"
#include "ns3/flow-monitor-module.h"
#include "ns3/internet-module.h"
#include "ns3/network-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/traffic-control-module.h"

// This simple example shows how to use TrafficControlHelper to install a
// QueueDisc on a device.
//
// The default QueueDisc is a pfifo_fast with a capacity of 1000 packets (as in
// Linux). However, in this example, we install a RedQueueDisc with a capacity
// of 10000 packets.
//
// Network topology
//
//       10.1.1.0
// n0 -------------- n1
//    point-to-point
//
// The output will consist of all the traced changes in the length of the RED
// internal queue and in the length of the netdevice queue:
//
//    DevicePacketsInQueue 0 to 1
//    TcPacketsInQueue 7 to 8
//    TcPacketsInQueue 8 to 9
//    DevicePacketsInQueue 1 to 0
//    TcPacketsInQueue 9 to 8
//
// plus some statistics collected at the network layer (by the flow monitor)
// and the application layer. Finally, the number of packets dropped by the
// queuing discipline, the number of packets dropped by the netdevice and
// the number of packets requeued by the queuing discipline are reported.
//
// If the size of the DropTail queue of the netdevice were increased from 1
// to a large number (e.g. 1000), one would observe that the number of dropped
// packets goes to zero, but the latency grows in an uncontrolled manner. This
// is the so-called bufferbloat problem, and illustrates the importance of
// having a small device queue, so that the standing queues build in the traffic
// control layer where they can be managed by advanced queue discs rather than
// in the device layer.

using namespace ns3;

int main(int argc, char *argv[])
{
  double simulationTime = 10; // seconds
  // std::string transportProt = "Tcp";
  // std::string socketType;

  CommandLine cmd(__FILE__);
  // cmd.AddValue("transportProt", "Transport protocol to use: Tcp, Udp", transportProt);
  cmd.Parse(argc, argv);

  NodeContainer nodes;
  nodes.Create(4);

  PointToPointHelper pointToPoint;
  pointToPoint.SetDeviceAttribute("DataRate", StringValue("10Mbps"));
  pointToPoint.SetChannelAttribute("Delay", StringValue("2ms"));
  pointToPoint.SetQueue("ns3::DropTailQueue", "MaxSize", StringValue("1p"));

  InternetStackHelper stack;
  stack.Install(nodes);

  Ipv4AddressHelper address;
  address.SetBase("10.1.1.0", "255.255.255.0");

  NetDeviceContainer devices;
  devices = pointToPoint.Install(nodes.Get(0), nodes.Get(1));
  Ipv4InterfaceContainer interfaces = address.Assign(devices);

  devices = pointToPoint.Install(nodes.Get(1), nodes.Get(2));
  address.SetBase("10.1.2.0", "255.255.255.0");
  interfaces = address.Assign(devices);

  Ipv4AddressHelper address1;
  address.SetBase("10.1.3.0", "255.255.255.0");

  NetDeviceContainer devices1;
  devices1 = pointToPoint.Install(nodes.Get(3), nodes.Get(1));
  Ipv4InterfaceContainer interfaces1 = address.Assign(devices1);

  devices1 = pointToPoint.Install(nodes.Get(1), nodes.Get(2));
  address.SetBase("10.1.4.0", "255.255.255.0");
  interfaces1 = address.Assign(devices1);

  Ipv4GlobalRoutingHelper::PopulateRoutingTables();

  // Flow
  uint16_t port = 7;
  Address localAddress(InetSocketAddress(Ipv4Address::GetAny(), port));
  PacketSinkHelper packetSinkHelper("ns3::UdpSocketFactory", localAddress);
  ApplicationContainer sinkApp = packetSinkHelper.Install(nodes.Get(2));

  sinkApp.Start(Seconds(0.0));
  sinkApp.Stop(Seconds(simulationTime + 0.1));

  uint32_t payloadSize = 1448;
  Config::SetDefault("ns3::TcpSocket::SegmentSize", UintegerValue(payloadSize));

  OnOffHelper onoff("ns3::UdpSocketFactory", Ipv4Address::GetAny());
  onoff.SetAttribute("OnTime", StringValue("ns3::ConstantRandomVariable[Constant=1]"));
  onoff.SetAttribute("OffTime", StringValue("ns3::ConstantRandomVariable[Constant=0]"));
  onoff.SetAttribute("PacketSize", UintegerValue(payloadSize));
  onoff.SetAttribute("DataRate", StringValue("50Mbps")); // bit/s
  ApplicationContainer apps;

  InetSocketAddress rmt(interfaces.GetAddress(1), port);
  rmt.SetTos(0xb8);
  AddressValue remoteAddress(rmt);
  onoff.SetAttribute("Remote", remoteAddress);
  apps.Add(onoff.Install(nodes.Get(0)));
  apps.Start(Seconds(1.0));
  apps.Stop(Seconds(simulationTime + 0.1));

  uint16_t port1 = 9;
  Address localAddress1(InetSocketAddress(Ipv4Address::GetAny(), port1));
  PacketSinkHelper packetSinkHelper1("ns3::TcpSocketFactory", localAddress1);
  ApplicationContainer sinkApp1 = packetSinkHelper1.Install(nodes.Get(2));

  sinkApp1.Start(Seconds(0.0));
  sinkApp1.Stop(Seconds(simulationTime + 0.1));

  // uint32_t payloadSize = 1448;
  Config::SetDefault("ns3::TcpSocket::SegmentSize", UintegerValue(payloadSize));

  OnOffHelper onoff1("ns3::TcpSocketFactory", Ipv4Address::GetAny());
  onoff1.SetAttribute("OnTime", StringValue("ns3::ConstantRandomVariable[Constant=1]"));
  onoff1.SetAttribute("OffTime", StringValue("ns3::ConstantRandomVariable[Constant=0]"));
  onoff1.SetAttribute("PacketSize", UintegerValue(payloadSize));
  onoff1.SetAttribute("DataRate", StringValue("50Mbps")); // bit/s
  ApplicationContainer apps1;

  InetSocketAddress rmt1(interfaces1.GetAddress(1), port1);
  rmt1.SetTos(0xb8);
  AddressValue remoteAddress1(rmt1);
  onoff1.SetAttribute("Remote", remoteAddress1);
  apps1.Add(onoff1.Install(nodes.Get(3)));
  apps1.Start(Seconds(1.0));
  apps1.Stop(Seconds(simulationTime + 0.1));

  FlowMonitorHelper flowmon;
  Ptr<FlowMonitor> monitor = flowmon.InstallAll();

  Simulator::Stop(Seconds(simulationTime + 5));
  Simulator::Run();

  Ptr<Ipv4FlowClassifier> classifier = DynamicCast<Ipv4FlowClassifier>(flowmon.GetClassifier());
  std::map<FlowId, FlowMonitor::FlowStats> stats = monitor->GetFlowStats();
  std::cout << std::endl
            << "*** Flow monitor statistics ***" << std::endl;
  std::cout << "  Tx Packets/Bytes:   " << stats[1].txPackets << " / " << stats[1].txBytes
            << std::endl;
  std::cout << "  Offered Load: "
            << stats[1].txBytes * 8.0 /
                   (stats[1].timeLastTxPacket.GetSeconds() -
                    stats[1].timeFirstTxPacket.GetSeconds()) /
                   1000000
            << " Mbps" << std::endl;
  std::cout << "  Rx Packets/Bytes:   " << stats[1].rxPackets << " / " << stats[1].rxBytes
            << std::endl;
  uint32_t packetsDroppedByQueueDisc = 0;
  uint64_t bytesDroppedByQueueDisc = 0;
  if (stats[1].packetsDropped.size() > Ipv4FlowProbe::DROP_QUEUE_DISC)
  {
    packetsDroppedByQueueDisc = stats[1].packetsDropped[Ipv4FlowProbe::DROP_QUEUE_DISC];
    bytesDroppedByQueueDisc = stats[1].bytesDropped[Ipv4FlowProbe::DROP_QUEUE_DISC];
  }
  std::cout << "  Packets/Bytes Dropped by Queue Disc:   " << packetsDroppedByQueueDisc << " / "
            << bytesDroppedByQueueDisc << std::endl;

  Simulator::Destroy();

  return 0;
}
