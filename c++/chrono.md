1. duration_cast

cast from one unit to another unit explicitly, but if lossless, can do implictly converstion. e.g, 

auto x = 2h; // 2 hour

milliseconds y = x; // loseless, y = 7'200'000ms. 

but if another way:

auto x = duration_cast\<hours\>(y); this is a lose conversion.
