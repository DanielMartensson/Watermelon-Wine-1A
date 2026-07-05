#!/usr/bin/env python3

# This is stm32mp257 LTDC upper limit
pixel_clk_max = 102000000

# FLEXGEN range
clk_divs = set(range(1, 65))

# Target pixelclock frequencies,
# obtained from dumping supported
# modes from a HD TV/monitor.
pixel_clk_targets = [
#	148500000,
#	148352000,
#	148500000,
#	135000000,
#	119000000,
#	108000000,
	88750000,
	78750000,
	75000000,
	74250000,
	74176000,
	65000000,
	57284000,
	50000000,
	49500000,
	40000000,
	36000000,
	31500000,
	30240000,
	28320000,
	27027000,
	27000000,
	25200000,
	25175000,
]

# Sanity check targets, there is no point
# optimizing for a frequency that is not
# supported anyway.
for f in pixel_clk_targets:
	print('INFO: target pixel clock {}'.format(f))
	if f > pixel_clk_max:
		print('WARNING: pixel clock {} is higher then max {}'.format(str(f),str(pixel_clk_max)))

found = {}

# Generete offsets from 0 to pixel_clk_max - 1 in MHz
offsets = range(0, 102)
for o in offsets:
	tc = pixel_clk_max + o * 1000000
	# Bruteforce a large number of multiples, thus
	# justifying the offset range not to
	# exceed pixel_clk_max * 2
	for fm in range(1, 16):
		test_clk = tc * fm
		err_sum = 0
		for ft in pixel_clk_targets:
			# Sum all error for all targeted modes
			dx = test_clk // ft
			if dx not in clk_divs:
				# Since no sane divisor exists
				# the error is therfore the
				# targed frequency
				err_sum += ft
			else:
				# Pick the minimum error to sum
				err_sum += min(abs(test_clk - dx * ft), abs(test_clk - (dx + 1) * ft))
		# Keep the lowest frequency for a given error
		if err_sum in found:
			if found[err_sum] > test_clk:
				found[err_sum] = test_clk
		else:
			found[err_sum] = test_clk

n = 0
for k in sorted(found.keys()):
	print('INFO: error {} with parent clk {}'.format(str(k), str(found[k])))
	if n >= 30:
		break
	else:
		n += 1
