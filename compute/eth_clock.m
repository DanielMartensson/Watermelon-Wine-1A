% ============================================================
% RGMII Trace Length & Delay Analysis - STM32MP257 + RTL8211F
% ============================================================

% PCB parameters
t = 1.6;          % PCB thickness (mm)
L = 1.0;          % 0402 series resistor length on RX (mm)
ps_per_mm = 20;   % Propagation delay (ps/mm)

% -------------------- TX (MAC → PHY) --------------------
RGMII_TXC    = 35.509 + t;
RGMII_TX_CTL = 34.952 + t;
RGMII_TD0    = 28.692 + t;
RGMII_TD1    = 27.109 + t;
RGMII_TD2    = 27.496 + t;
RGMII_TD3    = 28.286 + t;

% -------------------- RX (PHY → MAC) --------------------
RGMII_RXC    = 16.148 + 12.826 + t + L;
RGMII_RX_CTL = 22.815 + 16.217 + t + L;
RGMII_RD0    = 14.798 + 12.392 + t + L;
RGMII_RD1    = 18.939 + 13.266 + t + L;
RGMII_RD2    = 21.060 + 15.086 + t + L;
RGMII_RD3    = 16.203 + 25.792 + t + L;

% -------------------- MDIO / MDC --------------------
RGMII_MDIO   = 24.751 + 9.361 + t + L;
RGMII_MDC    = 20.697 + 12.647 + t + L;

% -------------------- Arrays --------------------
TX_names   = {'TXC', 'TX_CTL', 'TD0', 'TD1', 'TD2', 'TD3'};
TX_lengths = [RGMII_TXC, RGMII_TX_CTL, RGMII_TD0, RGMII_TD1, RGMII_TD2, RGMII_TD3];
TX_delay   = TX_lengths * ps_per_mm;

RX_names   = {'RXC', 'RX_CTL', 'RD0', 'RD1', 'RD2', 'RD3'};
RX_lengths = [RGMII_RXC, RGMII_RX_CTL, RGMII_RD0, RGMII_RD1, RGMII_RD2, RGMII_RD3];
RX_delay   = RX_lengths * ps_per_mm;

% -------------------- Print TX --------------------
fprintf('\n==================== TX-sidan (MAC → PHY) ====================\n');
fprintf('%-10s %10s %12s\n', 'Signal', 'Length', 'Delay');
fprintf('%-10s %10s %12s\n', '------', '------', '-----');
for i = 1:length(TX_names)
    fprintf('%-10s %8.3f mm %8.1f ps\n', TX_names{i}, TX_lengths(i), TX_delay(i));
end

tx_skew_ps = max(TX_delay(3:6)) - TX_delay(1);
fprintf('\nTXC vs data skew : %+.1f ps  (%+.3f ns)\n', tx_skew_ps, tx_skew_ps/1000);
if tx_skew_ps < 0
    fprintf('→ TXC is longest (good)\n');
else
    fprintf('→ Data is longer than TXC (not ideal)\n');
end

% -------------------- Print RX --------------------
fprintf('\n==================== RX-sidan (PHY → MAC) ====================\n');
fprintf('%-10s %10s %12s\n', 'Signal', 'Length', 'Delay');
fprintf('%-10s %10s %12s\n', '------', '------', '-----');
for i = 1:length(RX_names)
    fprintf('%-10s %8.3f mm %8.1f ps\n', RX_names{i}, RX_lengths(i), RX_delay(i));
end

rx_skew_ps = max(RX_delay(2:6)) - RX_delay(1);
fprintf('\nmax(RD/CTL) - RXC skew : %+.1f ps  (%+.3f ns)\n', rx_skew_ps, rx_skew_ps/1000);

% -------------------- Summary --------------------
fprintf('\n==================== Sammanfattning ====================\n');
fprintf('TX max skew : %6.1f ps (%5.3f ns)\n', abs(tx_skew_ps), abs(tx_skew_ps)/1000);
fprintf('RX max skew : %6.1f ps (%5.3f ns)\n', rx_skew_ps, rx_skew_ps/1000);
fprintf('======================================================\n\n');
