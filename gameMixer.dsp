import("stdfaust.lib");

import("libs/gameConfig.lib");

gameToneIN = _;
gameAccordIN = _, _;
gameArpIN = _;

tone = gameToneIN * mapFromMIDIscale(gameToneLevel) : _ * gameToneON;
accord = gameAccordIN : par(i, 2, (_ * mapFromMIDIscale(gameAccordLevel) : _ * gameAccordON)); 

process = (tone : sp.panner(gameTonePan)), accord :> co.limiter_1176_R4_stereo <: _, _;