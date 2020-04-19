import("stdfaust.lib");

import("libs/gameConfig.lib");

gameToneIN = _;
gameAccordIN = _, _;
gameArpIN = _;

tone = gameToneIN * mapFromMIDIscale(gameToneLevel) : _ * gameToneON;
accord = gameAccordIN : par(i, 2, (_ * mapFromMIDIscale(gameAccordLevel) : _ * gameAccordON)); 
arp = gameArpIN * mapFromMIDIscale(gameArpLevel) : _ * gameArpON;

process = tone, accord, arp :> co.limiter_1176_R4_stereo <: _, _;