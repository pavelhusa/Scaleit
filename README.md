# Scale it

'Scale it' is an open-source program (written in graphical programming language Pure data and Faust) that allows sonification of signal distribution in real-time. "Scale it" is being developed primarily for neurofeedback purposes. To allow the straightforward and customizable instrument to carry sonic feedback about EEG activity in specific neocortex regions.

## Games

There are two different possibilities for sonification of the signal. One of the objects, tone, generates changes in pitch of a monophonic tone. The other object, chord, expresses the input value in the width of polyphony.

<!--transcribe-->

### [Game Accord](gameAccord.dsp)
Polyphonic version of Game Tone combined with below thresh.

### [Game Accord synth](gameAccordSynth.dsp)
Polyphonic version of Game Tone.

### [Game Tone](gameTone.dsp)
Monophonic synth game combined with belowThresh.

### [Game Tone Synth](gameToneSynth.dsp)
Monophonic synth game.

<!--/transcribe-->

## Configuration documentation

<!--transcribe-->

### [Game configuration](libs/gameConfig.lib)
Configuration and inputs definition for all listed games.

**inputsN** general number of inputs for each game

#### TONE ACCORD
| Parameter name | default value | min value | max value | step |
| --- | --- | --- | --- | --- |
|baseKeyMIDI|69|0|128|1|
|oscType|0|0|4|1|
|subOscType|2|0|4|1|
|scale|0|0|scalesN-1|1|
|synthLevel|64|0|127|1|
|noiseLevel|0|0|127|1|
|activeSteps|8|0|12|1|
|subSynthLevel|127|0|127|1|

#### ARPEGGIATOR
| Parameter name | default value | min value | max value | step |
| --- | --- | --- | --- | --- |
|seqTempo|120|40|200|1|
|seqLevel|64|0|127|1|
|seqOn|1|0|1|1|
|seqPulseLen|0.1|0.1|1|0.01|
|seqStepsContinue|0|0|1|1|

#### COUNTER
| Parameter name | default value | min value | max value | step |
| --- | --- | --- | --- | --- |
|holdSec|4|0|10|0.01|
|resetCounter|0|0|1|1|

#### ENVELOPE 
| Parameter name | default value | min value | max value | step |
| --- | --- | --- | --- | --- |
|envAttack|1|0|5|0.05|
|envDecay|1|0|5|0.05|
|envSustain|1|0|1|0.05|
|envRelease|0.5|0|5|0.05|

#### MIXER
| Parameter name | default value | min value | max value | step |
| --- | --- | --- | --- | --- |
|gameToneLevel|64|0|127|1|
|gameAccordLevel|64|0|127|1|
|gameArpLevel|64|0|127|1|
|gameToneON|0|0|1|1|
|gameAccordON|0|0|1|1|
|gameArpON|0|0|1|1|
|gameTonePan|0.5|0|1|0.01|
|gameArpPan|0.5|0|1|0.01|

### [Scale configuration](libs/scaleEngine.lib)
Listed scales/chords are defined as a relative step from the base MIDI note number. Tones are limited to 12 tones. A more dynamic approach to extending available notes and custom scales will follow. Currently is available 16 scales/chords.

#### Modes
major scale
{0, 2, 4, 5, 7, 9, 11, 12, 14, 16, 17, 19}

dorian scale {0, 2, 3, 5, 7, 9, 10, 12, 14, 15, 17, 19}

phrygian scale {0, 1, 3, 5, 7, 8, 10, 12, 13, 15, 17, 19}

lydian scale {0, 2, 4, 6, 7, 9, 11, 12, 14, 16, 17, 18}

mixolydian scale {0, 2, 4, 5, 7, 9, 10, 12, 14, 15, 17, 18}

(aeolian) minor scale {0, 2, 3, 5, 7, 8, 10, 12, 14, 15, 17, 18}

locryan scale {0, 1, 3, 5, 6, 8, 10, 12, 13, 15, 17, 18}

#### Pentatonics
major pentatonic {0, 2, 4, 7, 9, 12, 14, 16, 19, 21, 24, 26, 28}

minor pentatonic {0, 3, 5, 7, 10, 12, 15, 17, 19, 22, 24, 27, 29}

iwato {0, 1, 5, 6, 10, 12, 13, 17, 18, 22, 24, 25}

hirajoshi {0, 2, 3, 7, 8, 12, 14, 15, 19, 20, 24, 26}

#### Symetric scales
chromatic scale {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13}

whole tone {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22}

#### Chords
major chord {0, 4, 7, 12, 16, 19, 24, 28, 31, 36, 40, 43}

major seventh chord {0, 4, 7, 11, 12, 16, 19, 23, 24, 28, 31, 35}

minor chord {0, 3, 7, 12, 15, 19, 24, 27, 31, 36, 39, 43}

### [Oscillator engine](libs/synthEngine.lib)
Oscillators are shared within all *synth.dsp files. Currently sawtooth, sine, triangle and square with noise is awailable. Also basic ASR envelope is handled here.

### [Threshold configuration](libs/threshConfig.lib)
Threshold stages for comparing with input signal.

|Name | description |
| -- | -- |
|intervalN|Maximum number of stages between low and high threshold.|
|lowThresh |Low threshold |
|hiThresh |High threshold |

| Parameter name | default value | min value | max value | step |
| --- | --- | --- | --- | --- |
|activeSteps|8|0|intervalN|1|
|invert|0|0|1|1|
|exclusive|0|0|1|1|
|curve|0|-10|10|0.01|

<!--/transcribe-->
