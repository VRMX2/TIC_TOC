simple NoeudJeton
{
    parameters:
        int maxTours = default(3);
    gates:
        input in;
        output out;
}

network Jeton
{
    submodules:
        n1: NoeudJeton;
        n2: NoeudJeton;
        n3: NoeudJeton;
        n4: NoeudJeton;
        n5: NoeudJeton;
    connections:
        n1.out --> {delay = 100ms;} --> n2.in;
        n2.out --> {delay = 100ms;} --> n3.in;
        n3.out --> {delay = 100ms;} --> n4.in;
        n4.out --> {delay = 100ms;} --> n5.in;
        n5.out --> {delay = 100ms;} --> n1.in;
}