import("stdfaust.lib");

import("libs/gameConfig.lib");
import("libs/threshConfig.lib");
import("libs/scaleEngine.lib");
import("libs/synthEngine.lib");

triggerIN = 1;

out = checkInputVal <: (counter <: toFrequency(_) <: sequencer(_)) * _
with {
    checkInputVal = ba.if(_ == 0, 0, 1);
    beater = ba.beat(seqTempo);

    counter(n) = beater * (n > 0) : ba.pulse_countup_loop(activeSteps-1, ba.if(seqStepsContinue, 1, n)) : int;

    toFrequency(n) = ba.midikey2hz(baseKeyMIDI+getTone(n));
    sequencer(p) = pulseSeq(p, beater);
};

process = out;