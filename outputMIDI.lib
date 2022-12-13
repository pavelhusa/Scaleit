import("stdfaust.lib");

import("libs/gameConfig.lib");
import("libs/scaleEngine.lib");
import("libs/synthEngine.lib");
import("libs/threshConfig.lib");

outputMIDI = MIDInoteNumber <: getMinMax
with {
    MIDInoteNumber = par(i, inputsN, getMIDI(i) * _) ;
    getMIDI(x) = ba.if(scaleDown, toMIDIDown(x), toMIDI(x));
    toMIDI(n) = baseKeyMIDI+getTone(n);
    toMIDIDown(n) = ba.if(inv == 0, baseKeyMIDI+getTone(n), baseKeyMIDI-getTone(n));
    getMinMax = ba.if(inv == 0, ba.parallelMax(inputsN), ba.parallelMin(inputsN));
};
