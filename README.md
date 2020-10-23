# LGen
An evolutionary approach to optimizing L-systems.

This is the source code for the publication [Evolving L-systems in a competitive environment](https://doi.org/10.1007/978-3-030-61864-3_28). A PDF version of the paper can be downloaded [here](https://jobtalle.com/posts/2020_10_20/EvolvingLSystems.pdf).

See [my website](https://jobtalle.com/evolving_lindenmayer_systems.html) for a short write up on this experment.

To set up a simple simulation that runs for two minutes, run the following commands:

```
sys new
sys a *
env new
env terrain valleys 20 20 10
env init 0.5
sim new
sim density 25
sim render
sim advance-s 120
```

These commands initialize a 20x20 simulation environments with lindenmayer systems with the axiom `*` and without rules. The systems are planted every 0.5 meters in the environments. The density factor is set to `25`, and the simulation runs for 120 seconds.
