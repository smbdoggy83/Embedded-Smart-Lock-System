
% This script flips the signal of the door
% if DOOR = ON, turn OFF, and if DOOR = OFF, turn ON
data = thingSpeakRead(1563202)

if (data(1) == 1)
    thingSpeakWrite(1563202, 0, 'WriteKey', 'H1R0O90R97HW8O8V')
end
if (data(1) == 0)
    thingSpeakWrite(1563202, 1, 'WriteKey', 'H1R0O90R97HW8O8V')
end

% thingSpeakWrite(1563202, 1, 'WriteKey', 'H1R0O90R97HW8O8V')

data = thingSpeakRead(1563202) % to check
