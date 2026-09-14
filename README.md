# Vdv301ApcTester

Program to read count numbers from Iris Irma 6 sensor using IBIS-IP protocol (VDV301, PassengerCountingService V2.1)


## Changelog 
- 20260914_1718
  - ITXPTsubscriber::postSubscribe
    - changed connect on reply finished
    - set subnet mask fix
    
- 20250424
    - base of ITXPTsubscriber
    - moved subscriber classes to VDV301subscriber submodule
    - first functional implementation of multiple publisher subscriber
- 20250331_1929
    - initial commit