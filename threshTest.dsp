import("stdfaust.lib");

import("libs/threshConfig.lib");

curve = nentry("curve", 0, -1, 1, 0.001);

getStepRatioTest(n) = lowThresh + currentStepRation(n)
with {
  currentStepRation(i) = pseudoExp(i);
  pseudoLog(x) = (((curve : abs) * (x ^ (1/4)) + ((1 + curve) * (x)));
  pseudoExp(x) = (curve * ((x) ^ 4)) + ((1 - curve) * (x));
  linear(x) = x * (hiThresh - lowThresh);
};

process = getStepRatioTest(_);