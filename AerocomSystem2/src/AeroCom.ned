package aerocomsystem2;

network AeroCom
{
    parameters:
        int mode = default(1);
        int DLNumber = default(1);
        int ACNumber = default(1);
    submodules:
        AC[ACNumber]: AirCraft {}
        datalink[DLNumber]: DataLink {}
        CT: ControlTower {
            DLNumber = DLNumber;
        }
        oracle: Oracle {}
    connections:
        for i=0..DLNumber-1 {
            datalink[i].dataLinkOut --> CT.in[i];
        }
}
