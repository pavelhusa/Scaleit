import("stdfaust.lib");

import("libs/gameConfig.lib");
import("libs/scaleEngine.lib");
import("libs/synthEngine.lib");

// sumOfInputs = input : sum(i, inputsN, _) : ba.if(0, 1, _);x
// toMIDI(n, in, summed) = ba.if(ba.selector(n, inputsN) == ba.selector(n, inputsN), ba.midikey2hz(baseKeyMIDI+ba.take(n+1, activeScale)), 0);
// toMIDI(n, in, summed) = ba.if(in==summed, ba.midikey2hz(baseKeyMIDI+ba.take(n+1, activeScale)), 0);
// out = parallelBus <: (sumOfInputs <: parallelBus), parallelBus <: par(i, inputsN, compare(i))
// with {
//     compare(n) = ba.selector(n, inputsN) == ba.selector(n, inputsN);
// };
// freq = baseKeyMIDI + ba.take(input, activeScale) : ba.midikey2hz(_);
// tone = par(n,8, (activeScale : ba.selectn(8,n)));
// tone = majorScale(1)
// synths = activeOsc;
// toMIDI(n, out) = ba.if(out == 1, baseKeyMIDI+ba.take(n+1, activeScale), 0);

out = input : par(i, inputsN, toFrequency(i, _)) <: getMax :> int <: synth, tunedNoise
with {
    summed = parallelBus;
    toFrequency(n, in) = ba.if(in==1, ba.midikey2hz(baseKeyMIDI+getTone(n)), 0);
    //POSSIBLE SPACE FOR RECURSION - TODO!!
    getMax = par(n, inputsN/2, max) <: par(n, inputsN/4, max) : max, _ : max;
};

process = out :> smoothOutput;