//# ScaleIt
// Game Tone and Game Accord combined together to an all-in-one box.
import("stdfaust.lib");

import("libs/gameConfig.lib");
import("libs/threshConfig.lib");
import("libs/scaleEngine.lib");
import("libs/synthEngine.lib");

in = nentry("input", 0, 0, 11, 1) : int;

process = (baseKeyMIDI+getTone(in)) : vbargraph("out",0,128);