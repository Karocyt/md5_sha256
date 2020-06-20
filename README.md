# Hash Algorithms
## School project

Imperfect implementation of md5 and sha256 in naked C.
It's imperfect as it allocate the memory twice and doesn't stream the data, so it does not work for files that wont fit (twice) in memory
