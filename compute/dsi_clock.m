% Kortets totala tjocklek
T = 1.5996;

% Mellan top layer och second layer med prereg 0.11640mm i mellan
b = 0.1666;

% Hastighet
ps_per_mm = 20; % ps/mm

% Mellan ADV7535 och STM32MP257
DSI_CLK_P = 16.486;
DSI_CLK_N = 16.964;
DSI_D0_P = 15.661;
DSI_D0_N = 16.862;
DSI_D1_P = 15.316;
DSI_D1_N = 15.300;
DSI_D2_P = 17.339 + 2*T; % Två vior från top layer till bottom layer
DSI_D2_N = 17.375 + 2*T; % Två vior från top layer till bottom layer
DSI_D3_P = 16.243 + 2*T; % Två vior från top layer till bottom layer
DSI_D3_N = 16.742 + 2*T; % Två vior från top layer till bottom layer

ref = DSI_CLK_P;   % Referens = CLK_P

fprintf('=== Inter-Pair Skew vs DSI_CLK_P ===\n\n');

% Beräkna för varje datapair
data_P = [DSI_D0_P, DSI_D1_P, DSI_D2_P, DSI_D3_P];
data_N = [DSI_D0_N, DSI_D1_N, DSI_D2_N, DSI_D3_N];
names = {'D0', 'D1', 'D2', 'D3'};

for i = 1:4
    skew_P_mm = data_P(i) - ref;
    skew_N_mm = data_N(i) - ref;

    skew_P_ps = skew_P_mm * ps_per_mm;
    skew_N_ps = skew_N_mm * ps_per_mm;

    fprintf('%s_P: %.3f mm → %7.2f ps (%.4f ns)\n', names{i}, skew_P_mm, skew_P_ps, skew_P_ps/1000);
    fprintf('%s_N: %.3f mm → %7.2f ps (%.4f ns)\n\n', names{i}, skew_N_mm, skew_N_ps, skew_N_ps/1000);
end


% Mellan ECMF4-40A100N10 och ADV7535
TMDS_CLK_N = 2.414;
TMDS_CLK_P = 2.046;
TMDS_D0_N = 1.689;
TMDS_D0_P = 1.703;
TMDS_D1_N = 1.778;
TMDS_D1_P = 1.772;
TMDS_D2_N = 1.938;
TMDS_D2_P = 1.938;

ref = TMDS_CLK_P;   % Referens = TMDS_CLK_P

fprintf('=== Inter-Pair Skew vs TMDS_CLK_P ===\n\n');

data_P = [TMDS_D0_P, TMDS_D1_P, TMDS_D2_P];
data_N = [TMDS_D0_N, TMDS_D1_N, TMDS_D2_N];
names = {'D0', 'D1', 'D2'};

for i = 1:3
    skew_P_mm = data_P(i) - ref;
    skew_N_mm = data_N(i) - ref;

    skew_P_ps = skew_P_mm * ps_per_mm;
    skew_N_ps = skew_N_mm * ps_per_mm;

    fprintf('%s_P: %.3f mm → %7.2f ps (%.4f ns)\n', names{i}, skew_P_mm, skew_P_ps, skew_P_ps/1000);
    fprintf('%s_N: %.3f mm → %7.2f ps (%.4f ns)\n\n', names{i}, skew_N_mm, skew_N_ps, skew_N_ps/1000);
end

% Mellan ECMF4-40A100N10 och HOAUC HYC23-HDMID19-650
HDMI_CLK_N = 6.886 + 2*b;
HDMI_CLK_P = 7.110 + 2*b;
HDMI_RX0_N = 2.316;
HDMI_RX0_P = 2.305;
HDMI_RX1_N = 6.472 + 2*b;
HDMI_RX1_P = 6.478 + 2*b;
HDMI_RX2_N = 2.459;
HDMI_RX2_P = 2.469;

ref = HDMI_CLK_P;   % Referens = HDMI_CLK_P

fprintf('=== Inter-Pair Skew vs HDMI_CLK_P ===\n\n');

data_P = [HDMI_RX0_P, HDMI_RX1_P, HDMI_RX2_P];
data_N = [HDMI_RX0_N, HDMI_RX1_N, HDMI_RX2_N];
names = {'RX0', 'RX1', 'RX2'};

for i = 1:3
    skew_P_mm = data_P(i) - ref;
    skew_N_mm = data_N(i) - ref;

    skew_P_ps = skew_P_mm * ps_per_mm;
    skew_N_ps = skew_N_mm * ps_per_mm;

    fprintf('%s_P: %.3f mm → %7.2f ps (%.4f ns)\n', names{i}, skew_P_mm, skew_P_ps, skew_P_ps/1000);
    fprintf('%s_N: %.3f mm → %7.2f ps (%.4f ns)\n\n', names{i}, skew_N_mm, skew_N_ps, skew_N_ps/1000);
end

% Frekvens: 148.5 MHz = 148 500 000 Hz
% Period = 1 / frekvens = 6.734 ns = 6734 ps
% ADV7533 har tHold och tSetup som min 0.15 UI (1 UI = 6734/2 ps = 3367 ps)
% Här antar vi att ADV7535 har det samma

% Frekvens
f = 148.5e6;                    % Frekvens i Hz (148.5 MHz)

% Period (full klockperiod)
period_ns = 1 / f * 1e9;        % i nanosekunder
period_ps = 1 / f * 1e12;       % i picosekunder

fprintf('Klockperiod: %.3f ns = %.0f ps\n', period_ns, period_ps);

% 1 UI = halva perioden (enligt MIPI DSI timing diagram)
ui_ns = period_ns / 2;
ui_ps = period_ps / 2;

fprintf('1 UI = %.3f ns = %.0f ps\n\n', ui_ns, ui_ps);

% 0.15 UI (min setup/hold enligt ADV7533)
ui_015_ns = 0.15 * ui_ns;
ui_015_ps = 0.15 * ui_ps;

fprintf('0.15 UI (min Setup/Hold) = %.3f ns = %.0f ps\n', ui_015_ns, ui_015_ps);

