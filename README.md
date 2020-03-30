# CEREBRO
EEG music neurofeedback.
## Modules description

### Below Threshold (belowTresh.dsp)
Transform two inputs onto 8 binary (0 and 1). 
#### Config parameters
Name | Meaning | Values
---- | ------- | ------
invert | This inverts outputs values that is transformed. | 0 - lower threshold are all zeros (filled with 1)<br /> 1 - lower threshold are all ones (filled with 0)

### Above Threshold (aboveTresh.dsp)
Transform two inputs onto 8 binary (0 and 1).
#### Config parameters
Name | Meaning | Values
---- | ------- | ------
invert | This inverts outputs values that is transformed. | 0 - lower threshold are all zeros (filled with 1)<br /> 1 - lower threshold are all ones (filled with 0)

### Above Threshold Counter (aboveTreshCounter.dsp)
Holds value of seconds above threshold inner value is cumulative. 
#### Config parameters
Name | Meaning | Values
---- | ------- | ------
holdSec | Integer value of seconds that should be hold above threshold | positive integer

### Game Tone (gameToneSynth.dsp)
Change single tone accordingly to input level. Tone, scale and noise are configurable.
#### Config parameters
Name | Meaning | Values
---- | ------- | ------
baseKeyMIDI | Base freq in MIDI NOTE | 0-127
oscType | Oscillator type | 0 - sine <br /> 1 - sawtooth <br /> 3 - triangle <br /> 4 - square 
scaleSelector | Pick predefined scale type or chord | 0 - Major <br /> 1 - Minor <br /> 2 - Whole tone <br />  3 - Major chord <br /> 4 - Major seventh chord <br /> 5 - Minor chord
synthLevel | Level of synth tone | 0-127
noiseLevel | Level of tuned noise | 0-127

### Game Accord (gameAccordSynth.dsp)
Same as Game Tone, tones and/or noise are added (or subtracted).
#### Config parameters
Name | Meaning | Values
---- | ------- | ------
baseKeyMIDI | Base freq in MIDI NOTE | 0-127
oscType | Oscillator type* | 0 - sine <br /> 1 - sawtooth <br /> 3 - triangle <br /> 4 - square 
scaleSelector | Pick predefined scale type or chord | 0 - Major <br /> 1 - Minor <br /> 2 - Whole tone <br />  3 - Major chord <br /> 4 - Major seventh chord <br /> 5 - Minor chord
synthLevel | Level of synth tone | 0-127
noiseLevel | Level of tuned noise | 0-127

### Game Arpeggiator (aboveArpSynth.dsp)
Music eight steps arpeggiator, number of steps depends on input. Matched with module Above Threshold Counter.
#### Config parameters
Name | Meaning | Values
---- | ------- | ------
seqTempo | Mater tempo of arpeggiator in BPM | 40-200
seqLevel | Volume level of sequencer output | 0-127
seqON | Toggles the arpeggiator | 0 - off <br /> 1 - on
seqPulseLen | Length of each tone in sequence in seconds | 0.1-1
baseKeyMIDI | Base freq in MIDI NOTE | 0-127
oscType | Oscillator type* | 0 - sine <br /> 1 - sawtooth <br /> 3 - triangle <br /> 4 - square 
scaleSelector | Pick predefined scale type or chord | 0 - Major <br /> 1 - Minor <br /> 2 - Whole tone <br />  3 - Major chord <br /> 4 - Major seventh chord <br /> 5 - Minor chord

### Game Mixer (aboveMixer.dsp)
Helper module that provides mixing and outputing each game. Inputs are wired from left to right: Game Tone, Game Accord, Game Arpeggiator
#### Config parameters
Name | Meaning | Values
---- | ------- | ------
gameToneLevel | Volume level of Game Tone | 0-127
gameAccordLevel | Volume level of Game Accord | 0-127
gameArpLevel | Volume level of Game Arp | 0-127
gameToneON | Game Tone master killswitch | 0-1
gameAccordON | Game Accord master killswitch | 0-1
gameArpON | Game Arpeggiator master killswitch | 0-1
