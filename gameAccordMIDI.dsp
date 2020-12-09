import("stdfaust.lib");

import("libs/gameConfig.lib");
import("libs/threshConfig.lib");
import("libs/scaleEngine.lib");

process = parallelBus <: par(i, inputsN, _ * (baseKeyMIDI+getTone(i)));
