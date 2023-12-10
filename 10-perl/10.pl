use strict;
use warnings;

open(my $in, "<", "input10");

my @lines = <$in>;
my $len = length($lines[0]);
$len = $len - 1;
print "$len\n";
map {print} @lines;

my $start_i = -1;
my $start_j = -1;

for my $i (0..scalar(@lines)-1) {
	for my $j (0..$len-1) {
		if (substr($lines[$i], $j, 1) eq 'S'){
			$start_i = $i;
			$start_j = $j;
			last;
		}
	}
	unless($start_i eq -1){
		last;
	}
}

print "$start_i $start_j \n";

sub canup {
	my $c = shift;
	if ($c eq '-' or $c eq 'L' or $c eq 'J' or $c eq '.'){
		return 0;
	}
	else{
		return 1;
	}
}
sub candown {
	my $c = shift;
	if ($c eq '-' or $c eq '7' or $c eq 'F' or $c eq '.'){
		return 0;
	}
	else{
		return 1;
	}
}
sub canleft {
	my $c = shift;
	if ($c eq '|' or $c eq 'J' or $c eq '7' or $c eq '.'){
		return 0;
	}
	else{
		return 1;
	}
}

sub canright {
	my $c = shift;
	if ($c eq '|' or $c eq 'L' or $c eq 'F' or $c eq '.'){
		return 0;
	}
	else{
		return 1;
	}
}

sub canmove {
	my $dir = shift;
	my $c = shift;
	my $curr_i = shift;
	my $curr_j = shift;
	if ($dir eq 'up'){
		if($curr_i < 0){
			return 0;
		}
		return canup($c);
	}
	if ($dir eq 'down'){
		if($curr_i == scalar(@lines)){
			return 0;
		}
		return candown($c);
	}
	if ($dir eq 'left'){
		if($curr_j < 0){
			return 0;
		}
		return canleft($c);
	}
	if ($dir eq 'right'){
		if($curr_j == $len ){
			return 0;
		}
		return canright($c);
	}
	
}

sub getdir{
	my $c = shift;
	my $dir = shift;
	if($c eq '|' or $c eq '-'){
		return $dir;
	}
	if($dir eq 'up'){
		if($c eq 'F'){
			return 'right';
		}
		if($c eq '7'){
			return 'left';
		}
	}
	if($dir eq 'down'){
		if($c eq 'L'){
			return 'right';
		}
		if($c eq 'J'){
			return 'left';
		}
	}
	if($dir eq 'left'){
		if($c eq 'L'){
			return 'up';
		}
		if($c eq 'F'){
			return 'down';
		}
	}
	if($dir eq 'right'){
		if($c eq '7'){
			return 'down';
		}
		if($c eq 'J'){
			return 'up';
		}
	}
}

my $loop = 0;

sub wegood {
	my $curr_i = shift;
	my $curr_j = shift;
	my $dir = shift;
	my $curr_v = substr($lines[$curr_i], $curr_j, 1);
	my $count = 1;
	my $loop = 0;
	my %loop_parts = (
		($curr_i * $len + $curr_j) => 1,
		($start_i * $len + $start_j) => 1,
	);
	while(1 == 1){
		# print "we see $curr_v while going $dir\n";
		if($curr_v eq 'S'){
			$loop = 1;
			last;
		}
		if(canmove($dir, $curr_v, $curr_i, $curr_j) == 0){
			last;
		}
		$dir = getdir($curr_v, $dir);
		# print "new_dir $dir\n";
		if($dir eq 'up'){
			$curr_i = $curr_i - 1;
		}
		if($dir eq 'down'){
			$curr_i = $curr_i + 1;
		}
		if($dir eq 'left'){
			$curr_j = $curr_j - 1;
		}
		if($dir eq 'right'){
			$curr_j = $curr_j + 1;
		}
		$loop_parts{($curr_i * $len + $curr_j)} = 1;
		$curr_v = substr($lines[$curr_i], $curr_j, 1);
		$count = $count + 1;
	}
	my $maxdist = $count/2;
	print "$loop loop-len: $count max-dist= $maxdist\n";
	my $area = 0;
	if($loop){
		for my $i (0..scalar(@lines)-1){
			my $p = 0;
			my $tophor = 0;
			my $bothor = 0;
			for my $j (0..$len-1){
					my $cv = substr($lines[$i], $j, 1);
					if(exists $loop_parts{$i * $len + $j}){
						if(substr($lines[$i], $j, 1) eq '-'){
						}
						if(substr($lines[$i], $j, 1) eq '|'){
							$p = 1 - $p;
						}
						if(substr($lines[$i], $j, 1) eq '7' or substr($lines[$i], $j, 1) eq 'S'){
							if($tophor == 0){
								$p = 1 - $p;
								$tophor = 0;
								$bothor = 0;
							}	
							else{
								$tophor = 0;
								$bothor = 0;
							}
						}
						if(substr($lines[$i], $j, 1) eq 'J'){
							# print "$i $j $bothor\n";
							if($bothor == 0){
								$p = 1 - $p;
								$tophor = 0;
								$bothor = 0;
							}
							else{
								$bothor = 0;
								$tophor = 0;
							}
						}
						if(substr($lines[$i], $j, 1) eq 'F'){
							$tophor = 1;
						}
						if(substr($lines[$i], $j, 1) eq 'L'){
							$bothor = 1;
						}
						# print "$p $cv # ";	
					}
					else{
						if($p == 1){
							$area = $area + 1;
							# print "$p $cv  ";
							# print "Area at ($i, $j) with $tophor and $bothor\n";
						}
						else{
							# print "$p $cv  ";

						}
					}
					
			}
			# print "\n";
		}
	}
	print "Area is $area\n";
}


if($start_i > 0){
	my $curr_i = $start_i - 1;
	my $curr_j = $start_j;
	my $curr_v = substr($lines[$curr_i], $curr_j, 1);
	my $dir = 'up';
	wegood($curr_i, $curr_j, $dir);
}
if($start_i < scalar(@lines) - 1){
	my $curr_i = $start_i + 1;
	my $curr_j = $start_j;
	my $curr_v = substr($lines[$curr_i], $curr_j, 1);
	my $dir = 'down';
	wegood($curr_i, $curr_j, $dir);
}
if($start_j > 0){
	my $curr_i = $start_i;
	my $curr_j = $start_j - 1;
	my $curr_v = substr($lines[$curr_i], $curr_j, 1);
	my $dir = 'left';
	wegood($curr_i, $curr_j, $dir);
}
if($start_j < $len - 1){
	my $curr_i = $start_i;
	my $curr_j = $start_j + 1;
	my $curr_v = substr($lines[$curr_i], $curr_j, 1);
	my $dir = 'right';
	wegood($curr_i, $curr_j, $dir);
}

print "hello world\n";
