Download ns3.39 
Extract the tar file in msrit  folder 

sudo apt-get update --fix-missing
sudo dpkg --configure -a
sudo apt-get install -f
python3 -m pip install --upgrade pip
python3 -m pip install --user cppyy
cd . .
./build.py --enable-examples --enable-tests
cd ns3.39
./ns3 configure --enable-python-bindings
./ns3 configure
./ns3 build
./ns3 run first --vis
