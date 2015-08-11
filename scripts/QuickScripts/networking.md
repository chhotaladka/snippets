Networking related terminal commands and features.
==================================================

1. Add a _bridge_ interface `br0`
  ```bash
  brctl addbr br0
  ```
  
2. Add a _Virtual ethernet_ interface pair `veth0` and `veth1`
  ```bash
  ip link add type veth
  ```
  
3. Add interface `veth0` to bridge `br0`
  ```bash
  brctl addif br0 veth0 
  ```  
  
4. Set MAC Address of an interface (say `veth0`)
  ```bash
  ifconfig veth0 hw ether 00:12:33:00:dd:56
  ```

5. Remove IP Address `10.10.1.3/24` from interface `eth1`
  ```bash
  ip addr del 10.10.1.3/24 dev eth1
  ```

6. Remove all IP Addresses from interface `eth1`
  ```bash
  ip addr flush dev eth1
  ```
  
