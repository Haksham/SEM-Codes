To get the <kbd> **tcp-variants-comparision.cc** </kbd> file , goto: 
<kbd>**Examples** </kbd> folder in <kbd> **ns-3.39** </kbd> folder-> <kbd> **tcp** </kbd> folder-> <kbd> **tcp-variants-comparison.cc** </kbd>  file.

Steps:

1. Copy the file and paste in <kbd> **scratch** </kbd> folder and rename it to <kbd> **final.cc** </kbd>

2. Do the following changes:

   In line number <ins>**345**</ins> of <kbd> **final.cc** </kbd> change "**TcpWestwoodPlus**" to " **TcpNewReno** " or " **TcpWestwoodPlus** ".

   in line <ins>**354**</ins> of <kbd> final.cc </kbd> , set <ins> **bool tracing** </ins> = <kbd> **false** </kbd> to <kbd> **true** </kbd>.

3. Then check the <kbd> **scratch** </kbd>folder again , you will find 2 new files as <kbd> TcpVariantsComparison-cwnd.data </kbd> and <kbd> **TcpVariantsComparison-rtt.data** </kbd>.

4. Use the data from those file to plot graph in xls file.