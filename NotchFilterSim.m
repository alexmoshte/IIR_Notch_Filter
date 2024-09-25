
%% A MATLAB script to design and simulate an IIR notch filter that attenuates 50Hz power line interference for a biosignal data acquisition board

%% Frequency and period constants
T=1.91e-4; % Period of each channel
fs=1/T; %=5.2355kHz. Frequency of operation for each channel
W1d=2*pi*(47); %Digital filter 3db lowerside cuttoff frequency specification
Wnd=2*pi*(53); %Digital filter 3db upperside cuttoff frequency specification
W=(((2/T)*(tan((Wnd/2)*T)))-((2/T)*(tan((W1d/2)*T)))); % Warped analog filter frequency bandwidth specification
Wd0=sqrt(W1d*Wnd); %Digital filter centre frequency
Woa=((2/T)*tan((Wd0/2)*T)); %Warped analog filter centre frequency

%% Lowpass prototype to lowpass analog filter
[B,A]=lp2bs(1,[1 sqrt(2) 1], Woa, W); %This function converts a lowpass prototype filter to a band stop filter with the warped frequncy specifications.Functions for converting to lowpass, highpass, and bandpass are also available. B and A are the coefficients of the corresponding analog filter laplace transform for our intended digital filter
 
%% Checking for Stability
TF=tf(B,A);
isstable(TF) %Returns logic 1 when the filter is stable. It follows that if the analog corresponding filter is stable, its digital corresponding filter is stable

%% Bilinear transform 
disp('Numerator coefficients b and Denominator coefficients a of the 4th order digital notch filter Z-tranform:');
[b,a]=bilinear(B,A,fs);%Implements a bilinear transform using B and A. b and a are the coefficients of the intended digital filter z-transform
disp(['b: ', num2str(b)]);
disp(['a: ', num2str(a)]);

%% Frequency response plots (magnitude and phase)
[hz, f]=freqz(b,a,512,fs); % Computes the frequency and phase response of the filter
magdB=20*log10(abs(hz)); %Converting magnitude to dB attenuation or gain. +ve dB=gain while -ve dB=atenuation
subplot(2,1,1), plot(f,magdB),grid; % Plots the magnitude response
axis([0 fs/50 -20 5]);  % Adjusting view according to filter characteristics
xlabel('Frequency (Hz)') 
ylabel('Magnitude (dB)') 
title('Frequency Response in dB')
 
phi=180*unwrap(angle(hz))/pi; %Converts the angles to radians
subplot(2,1,2), plot(f, phi); grid; % Plots the phase response
axis([0 fs/2-100 0]); % Adjusting view according to filter characteristics
xlabel('Frequency (Hz)')
ylabel('Phase (degrees)')
title('Phase Response')

%% Partial fractions for determining the difference equation (not important)
[R,P,K]=residue(b,a);

%% The Numerator and Denominator constants calculated manually. They are not utilized in the code. However, I included them just in case I needed to use them later

% Numerator constants
%A=((16/(T^4))+((8*(Woa^2))/(T^2)+(Woa^4)));
%B=(4*(Woa^4)-(64/(T^4)));
%C=((96/(T^4))-((16*(Woa^2))/(T^2))+(6*(Woa^4)));
%D=((4*Woa^4)-(64/(T^4)));
%E=((16/(T^4))+((8*(Woa^2))/(T^2))+(Woa^4));

% Denominator constants
%F=((16/(T^4))-((sqrt(2)*W*2*8)/(T^3))+((sqrt(2)*W*(Woa^2)*4)/(T))+(4*(Woa^4)));
%G=((4*(Woa^2))+((4*sqrt(2)*W*(Woa^2))/(T))-((16*sqrt(2)*W)/(T^3))-(64/(T^4))); 
%H=(((96)/(T^4))-((8*(W+(2*(Woa^2))))/(T^2))+(6*(Woa^4)));
%I=((4*(Woa^4))+((16*sqrt(2)*W)/(T^3))-((4*sqrt(2)*(Woa^2)*W)/(T))-(64/(T^4)));
%J=((Woa^4)+(16/(T^4))-((8*sqrt(2)*W)/(T^3))+((W+2*(Woa^2))*(4/(T^2)))-((2*sqrt(2)*W*(Woa^2))/(T)));


