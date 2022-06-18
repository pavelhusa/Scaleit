import("stdfaust.lib");

import("libs/threshConfig.lib");
import("libs/gameConfig.lib");
import("libs/outputConfig.lib");

process = input <: ba.if(inv, inv - (sum(i, inputsN, _) / activeSteps), (sum(i, inputsN, _) / activeSteps)) : threshMeterOutput;