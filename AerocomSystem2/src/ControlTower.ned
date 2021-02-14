package aerocomsystem2;

simple ControlTower
{
    parameters:
        int DLNumber;
        @signal[throughputSignal](type="double");
        @statistic[throughputStat](source="throughputSignal"; record=count);
        @signal[responseTimeSignal](type="double");
        @statistic[responseTimeStat](source="responseTimeSignal"; record=stats, vector);
    gates:
        input in[DLNumber];
}
