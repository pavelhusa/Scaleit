import("stdfaust.lib");

import("libs/gameConfig.lib");
import("libs/scaleEngine.lib");
import("libs/synthEngine.lib");

triggerIN = 1;

out = checkInputVal : int : counter~(_) <: toFrequency(_) : sequencer(_) * seqON
with {
    // steps = input :> _ <: ba.if(_ == 0, 1, _);
    // steps = 7;
    // steps = nentry("seqSteos", 1, 0, 7, 1);
    checkInputVal(x) = x <: ba.if(x <= 0, 1, _) : ba.if(x >= 8, 8, _);

    beater = ba.beat(seqTempo);
    steps(seqReset, steps) = ba.if(seqReset == 0, steps, _)~_;

    counter = (beater : ba.pulse_countup(seqON)), steps : _ % _ : int;

    toFrequency(n) = ba.midikey2hz(baseKeyMIDI+getTone(n));
    sequencer(p) = pulseSeq(p, beater);
};

process = out :> smoothOutput;