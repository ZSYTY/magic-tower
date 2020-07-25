

--
-- Table structure for table `tools`
--

CREATE TABLE IF NOT EXISTS `tools` (
  `id` integer PRIMARY KEY AUTOINCREMENT,
  `book` int NOT NULL,
  `shield` int NOT NULL,
  `sword` int NOT NULL
);

--
-- Insert data for table `tools`
--

DELETE FROM `tools`;
INSERT INTO `tools` (`id`, `book`, `shield`, `sword`) VALUES
(1, 0, 0, 0),
(2, 0, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `map`
--

CREATE TABLE IF NOT EXISTS `map` (
  `id` integer PRIMARY KEY AUTOINCREMENT,
  `data` varchar(15972) NOT NULL,
);

--
-- Insert data for table `map`
--

DELETE FROM `map`;
INSERT INTO `map` (`id`, `data`) VALUES
( 0, 'w,aw_1,aw_1,aw_1,aw_1,up,aw_1,aw_1,aw_1,aw_1,w,w,aw_1,aw_1,aw_1,aw_1,d_1,aw_1,aw_1,aw_1,aw_1,w,w,aw_1,aw_1,aw_1,aw_1,.,aw_1,aw_1,aw_1,aw_1,w,w,aw_1,aw_1,aw_1,aw_1,.,aw_1,aw_1,aw_1,aw_1,w,w,aw_1,aw_1,aw_1,aw_1,k_2.ini,aw_1,aw_1,aw_1,aw_1,w,w,aw_1,aw_1,aw_1,aw_1,k_1.ini,aw_1,aw_1,aw_1,aw_1,w,w,w,aw_1,aw_1,aw_1,k_0.ini,aw_1,aw_1,aw_1,w,w,w,w,w,w,w,dr_0.,w,w,w,w,w,aw_2,w,aw_2,w,.,me_4,.,w,aw_2,w,aw_2,aw_2,aw_2,aw_2,aw_2,aw_2,.,aw_2,aw_2,aw_2,aw_2,aw_2,aw_2,aw_2,aw_2,aw_2,aw_2,t,aw_2,aw_2,aw_2,aw_2,aw_2'
);

-- --------------------------------------------------------

--
-- Table structure for table `keys`
--

CREATE TABLE IF NOT EXISTS `keys` (
  `id` integer PRIMARY KEY AUTOINCREMENT,
  `red` int NOT NULL,
  `blue` int NOT NULL,
  `yellow` int NOT NULL
);

--
-- Insert data for table `keys`
--

DELETE FROM `keys`;
INSERT INTO `keys` (`id`, `red`, `blue`, `yellow`) VALUES
(1, 0, 0, 0),
(2, 0, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `monster`
--

CREATE TABLE IF NOT EXISTS `monster` (
  `id` integer PRIMARY KEY AUTOINCREMENT,
  `hp` int NOT NULL,
  `attack` int NOT NULL,
  `defend` int NOT NULL,
  `money` int NOT NULL,
  `exp` int NOT NULL,
  `miss` int NOT NULL,
  `crit` int NOT NULL
);

--
-- Insert data for table `monster`
--

DELETE FROM `monster`;
INSERT INTO `monster` (`hp`, `attack`, `defend`, `money`, `exp`, `miss`, `crit`, `id`) VALUES
(50, 12, 9, 3, 1, 5, 95, 11),
(60, 14, 10, 6, 3, 5, 94, 12),
(45, 20, 11, 10, 5, 7, 93, 13),
(150, 17, 7, 15, 7, 9, 92, 14),
(95, 35, 9, 20, 8, 9, 91, 15),
(50, 16, 35, 26, 10, 0, 90, 16),
(60, 17, 10, 15, 7, 45, 93, 17),
(100, 25, 20, 25, 15, 15, 92, 18),
(100, 30, 0, 0, 0, 20, 99, 19),
(100, 40, 13, 20, 20, 8, 50, 20),
(175, 45, 25, 40, 25, 5, 95, 21),
(150, 50, 30, 50, 25, 10, 90, 22),
(300, 60, 35, 0, 0, 20, 80, 23);

-- --------------------------------------------------------

--
-- Table structure for table `player`
--

CREATE TABLE IF NOT EXISTS `player` (
  `id` integer PRIMARY KEY AUTOINCREMENT,
  `hp` int NOT NULL,
  `attack` int NOT NULL,
  `defend` int NOT NULL,
  `money` int NOT NULL,
  `exp` int NOT NULL,
  `miss` int NOT NULL,
  `crit` int NOT NULL,
  `level` int NOT NULL,
  `posx` int NOT NULL,
  `posy` int NOT NULL,
  `floor` int NOT NULL,
  `toward` int NOT NULL,
  `sex` int NOT NULL,
  `need` int NOT NULL
 );

--
-- Insert data for table `player`
--

DELETE FROM `player`;
INSERT INTO `player` (`hp`, `attack`, `defend`, `money`, `exp`, `level`, `miss`, `crit`, `posx`, `posy`, `floor`, `toward`, `sex`, `need`, `id`) VALUES
(150, 14, 10, 0, 0, 0, 8, 93, 6, 12, 0, 3, 1, 5, 1),
(150, 14, 10, 0, 0, 0, 8, 93, 6, 12, 0, 3, 1, 5, 2);
