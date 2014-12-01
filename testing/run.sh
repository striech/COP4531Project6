mkdir -p results/unicode16
mkdir -p results/extended_ascii
mkdir -p results/uppercase
mkdir -p results/decimal
mkdir -p results/dna
mkdir -p results/binary

../sortspy_unicode16.x data/unicode16/random_10000 results/unicode16/random_10000
../sortspy_unicode16.x data/unicode16/sorted_10000 results/unicode16/sorted_10000
../sortspy_unicode16.x data/unicode16/reversed_10000 results/unicode16/reversed_10000
../sortspy_unicode16.x data/unicode16/duplicate_10000 results/unicode16/duplicate_10000
diff -q data/unicode16/sorted_10000 results/unicode16/random_10000.LSB
diff -q data/unicode16/sorted_10000 results/unicode16/sorted_10000.LSB
diff -q data/unicode16/sorted_10000 results/unicode16/reversed_10000.LSB
diff -q data/unicode16/sorted_10000 results/unicode16/duplicate_10000.LSB
diff -q data/unicode16/sorted_10000 results/unicode16/random_10000.MSB
diff -q data/unicode16/sorted_10000 results/unicode16/sorted_10000.MSB
diff -q data/unicode16/sorted_10000 results/unicode16/reversed_10000.MSB
diff -q data/unicode16/sorted_10000 results/unicode16/duplicate_10000.MSB
diff -q data/unicode16/sorted_10000 results/unicode16/random_10000.3WQS
diff -q data/unicode16/sorted_10000 results/unicode16/sorted_10000.3WQS
diff -q data/unicode16/sorted_10000 results/unicode16/reversed_10000.3WQS
diff -q data/unicode16/sorted_10000 results/unicode16/duplicate_10000.3WQS

../sortspy_extended_ascii.x data/extended_ascii/random_10000 results/extended_ascii/random_10000
../sortspy_extended_ascii.x data/extended_ascii/sorted_10000 results/extended_ascii/sorted_10000
../sortspy_extended_ascii.x data/extended_ascii/reversed_10000 results/extended_ascii/reversed_10000
../sortspy_extended_ascii.x data/extended_ascii/duplicate_10000 results/extended_ascii/duplicate_10000
diff -q data/extended_ascii/sorted_10000 results/extended_ascii/random_10000.LSB
diff -q data/extended_ascii/sorted_10000 results/extended_ascii/sorted_10000.LSB
diff -q data/extended_ascii/sorted_10000 results/extended_ascii/reversed_10000.LSB
diff -q data/extended_ascii/sorted_10000 results/extended_ascii/duplicate_10000.LSB
diff -q data/extended_ascii/sorted_10000 results/extended_ascii/random_10000.MSB
diff -q data/extended_ascii/sorted_10000 results/extended_ascii/sorted_10000.MSB
diff -q data/extended_ascii/sorted_10000 results/extended_ascii/reversed_10000.MSB
diff -q data/extended_ascii/sorted_10000 results/extended_ascii/duplicate_10000.MSB
diff -q data/extended_ascii/sorted_10000 results/extended_ascii/random_10000.3WQS
diff -q data/extended_ascii/sorted_10000 results/extended_ascii/sorted_10000.3WQS
diff -q data/extended_ascii/sorted_10000 results/extended_ascii/reversed_10000.3WQS
diff -q data/extended_ascii/sorted_10000 results/extended_ascii/duplicate_10000.3WQS

../sortspy_uppercase.x data/uppercase/random_10000 results/uppercase/random_10000
../sortspy_uppercase.x data/uppercase/sorted_10000 results/uppercase/sorted_10000
../sortspy_uppercase.x data/uppercase/reversed_10000 results/uppercase/reversed_10000
../sortspy_uppercase.x data/uppercase/duplicate_10000 results/uppercase/duplicate_10000
diff -q data/uppercase/sorted_10000 results/uppercase/random_10000.LSB
diff -q data/uppercase/sorted_10000 results/uppercase/sorted_10000.LSB
diff -q data/uppercase/sorted_10000 results/uppercase/reversed_10000.LSB
diff -q data/uppercase/sorted_10000 results/uppercase/duplicate_10000.LSB
diff -q data/uppercase/sorted_10000 results/uppercase/random_10000.MSB
diff -q data/uppercase/sorted_10000 results/uppercase/sorted_10000.MSB
diff -q data/uppercase/sorted_10000 results/uppercase/reversed_10000.MSB
diff -q data/uppercase/sorted_10000 results/uppercase/duplicate_10000.MSB
diff -q data/uppercase/sorted_10000 results/uppercase/random_10000.3WQS
diff -q data/uppercase/sorted_10000 results/uppercase/sorted_10000.3WQS
diff -q data/uppercase/sorted_10000 results/uppercase/reversed_10000.3WQS
diff -q data/uppercase/sorted_10000 results/uppercase/duplicate_10000.3WQS

../sortspy_decimal.x data/decimal/random_10000 results/decimal/random_10000
../sortspy_decimal.x data/decimal/sorted_10000 results/decimal/sorted_10000
../sortspy_decimal.x data/decimal/reversed_10000 results/decimal/reversed_10000
../sortspy_decimal.x data/decimal/duplicate_10000 results/decimal/duplicate_10000
diff -q data/decimal/sorted_10000 results/decimal/random_10000.LSB
diff -q data/decimal/sorted_10000 results/decimal/sorted_10000.LSB
diff -q data/decimal/sorted_10000 results/decimal/reversed_10000.LSB
diff -q data/decimal/sorted_10000 results/decimal/duplicate_10000.LSB
diff -q data/decimal/sorted_10000 results/decimal/random_10000.MSB
diff -q data/decimal/sorted_10000 results/decimal/sorted_10000.MSB
diff -q data/decimal/sorted_10000 results/decimal/reversed_10000.MSB
diff -q data/decimal/sorted_10000 results/decimal/duplicate_10000.MSB
diff -q data/decimal/sorted_10000 results/decimal/random_10000.3WQS
diff -q data/decimal/sorted_10000 results/decimal/sorted_10000.3WQS
diff -q data/decimal/sorted_10000 results/decimal/reversed_10000.3WQS
diff -q data/decimal/sorted_10000 results/decimal/duplicate_10000.3WQS

../sortspy_dna.x data/dna/random_10000 results/dna/random_10000
../sortspy_dna.x data/dna/sorted_10000 results/dna/sorted_10000
../sortspy_dna.x data/dna/reversed_10000 results/dna/reversed_10000
../sortspy_dna.x data/dna/duplicate_10000 results/dna/duplicate_10000
diff -q data/dna/sorted_10000 results/dna/random_10000.LSB
diff -q data/dna/sorted_10000 results/dna/sorted_10000.LSB
diff -q data/dna/sorted_10000 results/dna/reversed_10000.LSB
diff -q data/dna/sorted_10000 results/dna/duplicate_10000.LSB
diff -q data/dna/sorted_10000 results/dna/random_10000.MSB
diff -q data/dna/sorted_10000 results/dna/sorted_10000.MSB
diff -q data/dna/sorted_10000 results/dna/reversed_10000.MSB
diff -q data/dna/sorted_10000 results/dna/duplicate_10000.MSB
diff -q data/dna/sorted_10000 results/dna/random_10000.3WQS
diff -q data/dna/sorted_10000 results/dna/sorted_10000.3WQS
diff -q data/dna/sorted_10000 results/dna/reversed_10000.3WQS
diff -q data/dna/sorted_10000 results/dna/duplicate_10000.3WQS

../sortspy_binary.x data/binary/random_10000 results/binary/random_10000
../sortspy_binary.x data/binary/sorted_10000 results/binary/sorted_10000
../sortspy_binary.x data/binary/reversed_10000 results/binary/reversed_10000
../sortspy_binary.x data/binary/duplicate_10000 results/binary/duplicate_10000
diff -q data/binary/sorted_10000 results/binary/random_10000.LSB
diff -q data/binary/sorted_10000 results/binary/sorted_10000.LSB
diff -q data/binary/sorted_10000 results/binary/reversed_10000.LSB
diff -q data/binary/sorted_10000 results/binary/duplicate_10000.LSB
diff -q data/binary/sorted_10000 results/binary/random_10000.MSB
diff -q data/binary/sorted_10000 results/binary/sorted_10000.MSB
diff -q data/binary/sorted_10000 results/binary/reversed_10000.MSB
diff -q data/binary/sorted_10000 results/binary/duplicate_10000.MSB
diff -q data/binary/sorted_10000 results/binary/random_10000.3WQS
diff -q data/binary/sorted_10000 results/binary/sorted_10000.3WQS
diff -q data/binary/sorted_10000 results/binary/reversed_10000.3WQS
diff -q data/binary/sorted_10000 results/binary/duplicate_10000.3WQS