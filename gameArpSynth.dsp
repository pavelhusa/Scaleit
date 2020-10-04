import("stdfaust.lib");

import("libs/gameConfig.lib");
import("libs/threshConfig.lib");
import("libs/scaleEngine.lib");
import("libs/synthEngine.lib");

triggerIN = 1;

out = checkInputVal : counter <: toFrequency(_) <: sequencer(_)
with {
    checkInputVal(x) = x <: ba.if(x <= 0, 0, _) : ba.if(x >= activeSteps, activeSteps, _) : int; 

    beater = ba.beat(seqTempo);

    counter(n) = beater : ba.pulse_countup_loop(n,seqON) : int;

    toFrequency(n) = ba.midikey2hz(baseKeyMIDI+getTone(n));
    sequencer(p) = pulseSeq(p, beater);
};

process = out;