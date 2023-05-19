#!/bin/bash

# Helper function to test push_swap and print results
test_case() {
    input="$1"
    echo "Testing input: $input"
    output=$(./push_swap $input | ./checker_linux $input)
    echo "Output:"
    echo "$output"
    echo "--------------------------"
}

# Edge cases

# Single negative number
test_case "-5"

# Single positive number
test_case "5"

# Two numbers: negative and positive
test_case "-5 5"

# Two numbers: both negative
test_case "-5 -10"

# Two numbers: both positive
test_case "5 10"

# Three numbers: mix of negative and positive
test_case "-5 0 5"

# Multiple numbers with duplicates
test_case "1 2 3 4 5 1 2 3 4 5"

# Random cases
test_case "1 6 -8 10 -3 9 -3 15"
test_case "-4 9 12 -20 21 -1"
test_case "20 15 10 5 0 -5 -10 -15 -20"

# Additional edge cases

# Negative numbers in descending order
test_case "-1 -2 -3 -4 -5"

# Positive numbers in ascending order
test_case "1 2 3 4 5"

# Negative and positive numbers in mixed order
test_case "-1 2 -3 4 -5"

# Same number repeated multiple times
test_case "-5 -5 -5 -5 -5"

# Large positive and negative numbers
test_case "1000000 -1000000 500000 -500000 0"

# Additional edge cases

# All numbers are zero
test_case "0 0 0 0 0 0 0 0 0"

# Mix of small and large positive numbers
test_case "1 1000 10000 100000 1000000"

# Mix of small and large negative numbers
test_case "-1 -1000 -10000 -100000 -1000000"

# Large number of numbers in increasing order
test_case "$(seq -s ' ' 1 1 100)"

# Large number of numbers in decreasing order
test_case "$(seq -s ' ' -1 -1 -100)"

# Large number of alternating positive and negative numbers
test_case "$(for i in {1..50}; do echo $i -$i; done | tr '\n' ' ')"

# Large set of random positive and negative integers without duplicates
test_case "-1000 -998 -996 -994 -992 -990 992 994 996 998 1000 -986 -984 -982 -980 980 982 984 986 -976 -974 -972 -970 970 972 974 976 -966 -964 -962 -960 960 962 964 966 -956 -954 -952 -950 950 952 954 956 -946 -944 -942 -940 940 942 944 946 -936 -934 -932 -930 930 932 934 936 -926 -924 -922 -920 920 922 924 926 -916 -914 -912 -910 910 912 914 916 -906 -904 -902 -900 900 902 904 906 -896 -894 -892 -890 890 892 894 896 -886 -884 -882 -880 880 882 884 886 -876 -874 -872 -870 870 872 874 876 -866 -864 -862 -860 860 862 864 866 -856 -854 -852 -850 850 852 854 856 -846 -844 -842 -840 840 842 844 846 -836 -834 -832 -830 830 832 834 836 -826 -824 -822 -820 820 822 824 826 -816 -814 -812 -810 810 812 814 816 -806 -804 -802 -800 800 802 804 806 -796 -794 -792 -790 790 792 794 796 -786 -784 -782 -780 780 782 784 786 -776 -774 -772 -770 770 772 774 776 -766 -764 -762 -760 760 762 764 766 -756 -754 -752 -750 750 752 754 756 -746 -744 -742 -740 740 742 744 746 -736 -734 -732 -730 730 732 734 736 -726 -724 -722 -720 720 722 724 726 -716 -714 -712 -710 710 712 714 716 -706 -704 -702 -700 700 702 704 706 -696 -694 -692 -690 690 692 694 696 -686 -684 -682 -680 680 682 684 686 -676 -674 -672 -670 670 672 674 676 -666 -664 -662 -660 660 662 664 666 -656 -654 -652 -650 650 652 654 656 -646 -644 -642 -640 640 642 644 646 -636 -634 -632 -630 630 632 634 636 -626 -624 -622 -620 620 622 624 626 -616 -614 -612 -610 610 612 614 616 -606 -604 -602 -600 600 602 604 606 -596 -594 -592 -590 590 592 594 596 -586 -584 -582 -580 580 582 584 586 -576 -574 -572 -570 570 572 574 576 -566 -564 -562 -560 560 562 564 566 -556 -554 -552 -550 550 552 554 556 -546 -544 -542 -540 540 542 544"


echo "All tests finished!"
