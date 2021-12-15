
% This script flips the signal of the door, whatever it is
% if 0, turn to 1, if 1, turn to 0
data = thingSpeakRead(1563202)

if (data(1) == 1)
    thingSpeakWrite(1563202, 0, 'WriteKey', 'H1R0O90R97HW8O8V')
end
if (data(1) == 0)
    thingSpeakWrite(1563202, 1, 'WriteKey', 'H1R0O90R97HW8O8V')
end

% thingSpeakWrite(1563202, 1, 'WriteKey', 'H1R0O90R97HW8O8V')

data = thingSpeakRead(1563202) % to check
