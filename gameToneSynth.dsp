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

out = input <: toneTransform :  par(i, inputsN, _ <: envelope, (toFrequency(i) <: synth, tunedNoise :> _) : _ * _)
with {
    toneTransform = par(i, inputsN, _) <: (par(i, inputsN, _) , (!, par(i, inputsN-1, _): par(i, inputsN-1, _), 0)) <: par(i, inputsN, crossCompare(i));
    crossCompare(n) =  ba.selector(n, inputsN) != ba.selector(n, inputsN);
    toFrequency(n) = ba.midikey2hz(baseKeyMIDI+getTone(n));
};

process = out :> smoothOutput;