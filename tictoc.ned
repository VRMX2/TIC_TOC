simple Noeud
{
 gates:
 input in;
 output out;
}
network Tictoc
{
 submodules:
 tic: Noeud;
 toc: Noeud;
 connections:
 tic.out --> toc.in;
 tic.in <-- toc.out;
}