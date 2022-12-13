//# ScaleIt
// Game Tone and Game Accord combined together to an all-in-one box.
import("stdfaust.lib");
import("libs/comparator.lib");
import("libs/invertor.lib");
import("gameAccord.dsp");
import("gameTone.dsp");
import("outputMIDI.dsp");

process = compare : invertor <: (gameAccord, gameTone :> _, _), outputMIDI;