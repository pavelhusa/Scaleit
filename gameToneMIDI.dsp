import("stdfaust.lib");

import("libs/gameConfig.lib");
import("libs/scaleEngine.lib");
import("libs/synthEngine.lib");
import("libs/threshConfig.lib");

out = sumInput <: toneSelector : MIDInoteNumber
with {
    sumInput = input :> _;
    toneSelector(x) = exclusiveConditional : ba.selectoutn(inputsN, ba.if(inv == 0, (x + (excl : int)), ((activeSteps - x) + (excl : int)))) : par(i, inputsN, _);
    exclusiveConditional(x) = ba.if(((x == 0) & (excl == 1)), 0, 1);
    MIDInoteNumber = par(i, inputsN, getMIDI(i-(excl : int)) * _);

    getMIDI(x) = ba.if(scaleDown, toMIDIDown(x), toMIDI(x));
    toMIDI(n) = baseKeyMIDI+getTone(n);
    toMIDIDown(n) = ba.if(inv == 0, baseKeyMIDI+getTone(n), baseKeyMIDI-getTone(n));
};

process = out :> _;