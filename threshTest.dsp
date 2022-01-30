import("stdfaust.lib");

import("libs/threshConfig.lib");

curve = nentry("curve", 0, -10, 10, 0.01);

getStepRatioTest(n) = lowThresh + currentStepRation(n)
with {
  currentStepRation(i) = (i / activeSteps) ^ (2 ^ curve);
};

process = getStepRatioTest(_);