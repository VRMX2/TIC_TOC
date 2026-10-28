simple NoeudPeriodique
{
    parameters:
        int nb;
        double d;
    gates:
        input in;
        output out;
}

network JetonPeriodique
{
    submodules:
        n1: NoeudPeriodique;
        n2: NoeudPeriodique;
        n3: NoeudPeriodique;
        n4: NoeudPeriodique;
        n5: NoeudPeriodique;
        n6: NoeudPeriodique;
        n7: NoeudPeriodique;
        n8: NoeudPeriodique;
        n9: NoeudPeriodique;
        n10: NoeudPeriodique;
    connections:
        n1.out --> {delay = 100ms;} --> n2.in;
        n2.out --> {delay = 100ms;} --> n3.in;
        n3.out --> {delay = 100ms;} --> n4.in;
        n4.out --> {delay = 100ms;} --> n5.in;
        n5.out --> {delay = 100ms;} --> n6.in;
        n6.out --> {delay = 100ms;} --> n7.in;
        n7.out --> {delay = 100ms;} --> n8.in;
        n8.out --> {delay = 100ms;} --> n9.in;
        n9.out --> {delay = 100ms;} --> n10.in;
        n10.out --> {delay = 100ms;} --> n1.in;
}