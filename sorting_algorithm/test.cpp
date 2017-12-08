#include <iostream>
#include "sort.h"
#include <windows.h>



void main()
{
	int test[1000] = { 90, 634, 780, 215, 598, 525, 632, 295, 638, 94, 577, 444, 830, 318, 573, 641, 413, 99, 728, 801, 484, 46, 200, 102, 70, 265, 324, 962, 51, 929, 187, 429, 377, 402, 297, 704, 662, 894, 951, 10, 534, 145, 867, 169, 306, 947, 979, 954, 669, 982, 673, 748, 290, 59, 385, 759, 416, 845, 493, 791, 541, 508, 35, 250, 353, 925, 106, 305, 556, 615, 660, 919, 743, 559, 848, 553, 44, 821, 251, 565, 606, 348, 58, 487, 707, 893, 782, 975, 178, 774, 518, 570, 375, 247, 440, 32, 485, 168, 184, 765, 33, 453, 694, 144, 922, 654, 154, 227, 111, 129, 645, 873, 446, 679, 43, 630, 930, 107, 898, 691, 933, 193, 294, 201, 932, 28, 742, 427, 308, 736, 205, 17, 963, 217, 768, 202, 163, 224, 381, 536, 657, 465, 139, 157, 766, 430, 859, 189, 512, 858, 557, 839, 83, 504, 158, 895, 625, 690, 582, 96, 904, 100, 913, 837, 814, 652, 864, 884, 400, 698, 818, 331, 244, 150, 836, 620, 502, 892, 152, 55, 835, 717, 84, 478, 551, 473, 325, 273, 720, 829, 721, 514, 566, 840, 181, 403, 796, 226, 220, 737, 128, 966, 517, 328, 885, 341, 138, 896, 612, 316, 928, 513, 991, 287, 949, 338, 621, 291, 763, 584, 789, 663, 648, 225, 656, 204, 307, 141, 422, 853, 223, 262, 776, 459, 231, 655, 750, 519, 509, 310, 665, 186, 805, 834, 992, 506, 101, 563, 822, 944, 596, 117, 109, 529, 390, 415, 198, 950, 313, 995, 456, 406, 719, 288, 984, 629, 249, 31, 170, 692, 437, 668, 65, 749, 483, 408, 355, 103, 122, 701, 30, 78, 469, 292, 461, 733, 916, 806, 345, 394, 496, 418, 689, 700, 488, 165, 808, 197, 433, 370, 472, 323, 812, 524, 395, 874, 788, 458, 784, 599, 542, 216, 194, 346, 11, 19, 113, 335, 114, 730, 732, 155, 137, 450, 616, 260, 391, 941, 494, 69, 361, 401, 241, 274, 826, 729, 62, 799, 549, 909, 486, 811, 29, 923, 653, 797, 37, 161, 286, 539, 135, 386, 601, 82, 56, 627, 449, 964, 643, 912, 358, 431, 349, 687, 343, 16, 868, 968, 393, 451, 594, 948, 457, 392, 856, 935, 980, 303, 713, 192, 492, 24, 171, 647, 95, 819, 41, 339, 561, 602, 651, 160, 591, 741, 296, 397, 996, 147, 243, 54, 9, 116, 1, 421, 636, 261, 817, 501, 159, 230, 970, 258, 674, 267, 785, 326, 778, 611, 914, 432, 613, 176, 684, 681, 712, 278, 576, 569, 939, 123, 245, 977, 693, 238, 285, 191, 75, 208, 955, 34, 279, 27, 255, 14, 552, 376, 999, 938, 396, 555, 214, 50, 206, 709, 277, 334, 142, 760, 112, 886, 872, 688, 448, 507, 510, 89, 676, 419, 976, 978, 587, 841, 773, 63, 844, 589, 0, 574, 371, 921, 110, 658, 988, 407, 699, 531, 121, 6, 454, 562, 739, 271, 480, 786, 618, 398, 4, 528, 79, 815, 790, 724, 926, 312, 515, 540, 98, 357, 315, 134, 333, 614, 40, 633, 628, 177, 212, 852, 973, 993, 860, 705, 300, 983, 52, 219, 800, 901, 367, 520, 998, 237, 302, 426, 351, 850, 467, 259, 593, 824, 639, 931, 2, 609, 738, 564, 758, 489, 280, 523, 211, 87, 558, 842, 751, 828, 39, 775, 981, 592, 635, 283, 384, 752, 365, 180, 475, 42, 229, 463, 672, 682, 746, 722, 218, 327, 256, 130, 603, 961, 252, 441, 126, 846, 670, 360, 934, 64, 631, 857, 239, 203, 153, 697, 664, 470, 769, 903, 359, 173, 362, 270, 491, 761, 744, 847, 445, 974, 772, 548, 162, 347, 600, 207, 530, 809, 810, 409, 644, 703, 804, 499, 232, 185, 266, 794, 521, 299, 66, 503, 685, 918, 825, 45, 726, 26, 823, 73, 526, 680, 972, 714, 702, 936, 85, 76, 881, 236, 767, 175, 661, 166, 148, 597, 527, 57, 356, 38, 378, 133, 571, 471, 803, 575, 757, 74, 535, 210, 414, 579, 127, 659, 637, 671, 388, 764, 779, 282, 183, 533, 667, 971, 476, 908, 545, 71, 304, 646, 869, 221, 447, 617, 793, 787, 164, 281, 586, 428, 715, 104, 838, 753, 438, 482, 417, 264, 389, 595, 77, 735, 880, 585, 740, 547, 364, 174, 108, 762, 861, 81, 172, 269, 854, 460, 425, 623, 53, 289, 710, 511, 610, 581, 876, 213, 253, 590, 900, 607, 387, 865, 319, 242, 899, 329, 268, 605, 301, 716, 342, 943, 474, 957, 677, 424, 374, 13, 275, 695, 537, 871, 887, 91, 314, 167, 756, 3, 21, 580, 747, 47, 754, 443, 322, 498, 650, 678, 905, 452, 997, 49, 368, 340, 877, 257, 622, 136, 843, 119, 946, 350, 958, 911, 118, 468, 706, 878, 309, 298, 240, 423, 543, 755, 248, 344, 143, 366, 989, 466, 182, 373, 866, 151, 479, 952, 25, 209, 455, 354, 352, 708, 336, 464, 985, 80, 956, 234, 115, 146, 675, 337, 442, 942, 870, 60, 363, 330, 439, 924, 12, 477, 404, 462, 994, 640, 190, 399, 550, 890, 902, 572, 953, 20, 293, 883, 97, 36, 405, 771, 831, 272, 578, 723, 802, 583, 7, 538, 855, 940, 683, 945, 195, 18, 959, 696, 434, 832, 436, 608, 179, 910, 92, 807, 188, 228, 88, 67, 967, 816, 411, 882, 5, 276, 263, 849, 889, 619, 927, 777, 420, 888, 149, 783, 907, 649, 770, 235, 86, 505, 718, 156, 879, 727, 642, 196, 546, 412, 23, 8, 131, 48, 937, 745, 560, 284, 15, 906, 379, 875, 522, 624, 311, 383, 798, 986, 317, 568, 382, 321, 495, 813, 516, 532, 105, 833, 132, 781, 731, 990, 544, 22, 233, 965, 372, 863, 604, 969, 490, 917, 72, 792, 851, 254, 481, 626, 915, 920, 960, 369, 827, 891, 380, 120, 61, 666, 68, 320, 125, 554, 500, 820, 332, 795, 862, 199, 725, 140, 497, 124, 93, 711, 686, 897, 222, 567, 246, 588, 987, 410, 435, 734 };

	double time = 0;
	double counts = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);

	QueryPerformanceCounter(&nBeginTime); // Start the timer

	shell_sort(test,sizeof(test)/sizeof(int)); // Sort
	
	QueryPerformanceCounter(&nEndTime);	// End the timer   
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart; // Calculate the function run time



	for (int i = 0; i < 1000; i ++)
	{
		std::cout << test[i] << std::endl;
	}
	std::cout << "The run time is:" << time * 1000 << "ms" << std::endl;
	std::cin.get();
}
