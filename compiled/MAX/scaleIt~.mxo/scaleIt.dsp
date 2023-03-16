//# ScaleIt
// Game Tone and Game Accord combined together to an all-in-one box.
import("stdfaust.lib");
import("libs/comparator.lib");
import("libs/invertor.lib");
import("libs/playBelowAbove.lib");
import("gameAccord.lib");
import("gameTone.lib");
import("outputMIDI.lib");
import("threshMeter.lib");

process(_alpha, _thresh) = compare(_alpha, _thresh) : invertor <: (gameAccord, gameTone :> playBelowAbove(_alpha, _thresh), playBelowAbove(_alpha, _thresh)), outputMIDI, threshMeter;