# LGen
An evolutionary approach to optimizing L-systems.

See [my website](https://jobtalle.com/evolving_lindenmayer_systems.html) for an article and thesis on the experiments performed using this software.

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
