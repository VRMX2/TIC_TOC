simple NoeudRoute
{
    gates:
        inout p[];
}

network ReseauRoute
{
    @display("bgb=700,400");
    submodules:
        noeud[10]: NoeudRoute;
    connections:
        noeud[0].p++ <--> {delay=100ms;} <--> noeud[1].p++;
        noeud[0].p++ <--> {delay=100ms;} <--> noeud[2].p++;
        noeud[1].p++ <--> {delay=100ms;} <--> noeud[4].p++;
        noeud[4].p++ <--> {delay=100ms;} <--> noeud[6].p++;
        noeud[4].p++ <--> {delay=100ms;} <--> noeud[7].p++;
        noeud[2].p++ <--> {delay=100ms;} <--> noeud[3].p++;
        noeud[2].p++ <--> {delay=100ms;} <--> noeud[5].p++;
        noeud[2].p++ <--> {delay=100ms;} <--> noeud[7].p++;
        noeud[5].p++ <--> {delay=100ms;} <--> noeud[8].p++;
        noeud[7].p++ <--> {delay=100ms;} <--> noeud[8].p++;
        noeud[7].p++ <--> {delay=100ms;} <--> noeud[9].p++;
        noeud[8].p++ <--> {delay=100ms;} <--> noeud[9].p++;
}