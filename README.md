# CEREBRO
## Game Parameters
### Game Tone
Name | Meaning | Values
---- | ------- | ------
baseKeyMIDI | Base freq in MIDI NOTE | 0-128

baseKeyMIDI = nentry("baseKeyMIDI",69,0,128,1);
oscType = nentry("oscType", 0, 0, 4, 1);
scaleSelector = nentry("scale", 0, 0, scalesN-1, 1);
synthLevel = nentry("synthLevel", 0, 64, 127, 1);
noiseLevel = nentry("noiseLevel", 0, 0, 127, 1);
