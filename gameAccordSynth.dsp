import("stdfaust.lib");

import("libs/gameConfig.lib");
import("libs/threshConfig.lib");
import("libs/scaleEngine.lib");
import("libs/synthEngine.lib");

out = input : par(i, inputsN, _ <: (envelope <: _,_), (toFrequency(i) <: ((synth, tunedNoise) :> _), bassSynth(i)) : _,ro.cross(2),_ : par(i, 2, (_*_))) : par(i, inputsN, panorama(i), sp.panner(0.5))
with {
    toFrequency(n) = ba.midikey2hz(baseKeyMIDI+getTone(n));
    // envelope = en.asr(envTime,1,envTime*2);
    bassToneConditional = ba.if(inv == 0, bassTone-1, inputsN-bassTone+1);
    bassSynth(x) = ba.if(x == bassToneConditional, subSynth(toFrequency(0)), 0); 
    panorama(i) = sp.panner(nentry("accordPan%i", 0.5, 0, 1, 0.05));
};

process = out :> _,_ : par(i, 2, smoothOutput);