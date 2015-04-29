-- phpMyAdmin SQL Dump
-- version 3.4.11.1deb2+deb7u1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Apr 29, 2015 at 07:17 PM
-- Server version: 5.5.41
-- PHP Version: 5.4.39-0+deb7u1

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `baseball_stadiums`
--

-- --------------------------------------------------------

--
-- Stand-in structure for view `ASC_American_TeamName`
--
DROP VIEW IF EXISTS `ASC_American_TeamName`;
CREATE TABLE IF NOT EXISTS `ASC_American_TeamName` (
`stadiumName` varchar(50)
,`teamName` varchar(50)
,`street` varchar(50)
,`city` varchar(50)
,`state` varchar(30)
,`zip` varchar(10)
,`boxOfficeNum` varchar(20)
,`dateOpened` varchar(15)
,`capacity` varchar(50)
,`league` varchar(20)
,`surface` varchar(10)
);
-- --------------------------------------------------------

--
-- Stand-in structure for view `ASC_Date_Opened`
--
DROP VIEW IF EXISTS `ASC_Date_Opened`;
CREATE TABLE IF NOT EXISTS `ASC_Date_Opened` (
`stadiumName` varchar(50)
,`teamName` varchar(50)
,`street` varchar(50)
,`city` varchar(50)
,`state` varchar(30)
,`zip` varchar(10)
,`boxOfficeNum` varchar(20)
,`dateOpened` varchar(15)
,`capacity` varchar(50)
,`league` varchar(20)
,`surface` varchar(10)
);
-- --------------------------------------------------------

--
-- Stand-in structure for view `ASC_National_Team_Name`
--
DROP VIEW IF EXISTS `ASC_National_Team_Name`;
CREATE TABLE IF NOT EXISTS `ASC_National_Team_Name` (
`stadiumName` varchar(50)
,`teamName` varchar(50)
,`street` varchar(50)
,`city` varchar(50)
,`state` varchar(30)
,`zip` varchar(10)
,`boxOfficeNum` varchar(20)
,`dateOpened` varchar(15)
,`capacity` varchar(50)
,`league` varchar(20)
,`surface` varchar(10)
);
-- --------------------------------------------------------

--
-- Stand-in structure for view `ASC_Stadium_Name`
--
DROP VIEW IF EXISTS `ASC_Stadium_Name`;
CREATE TABLE IF NOT EXISTS `ASC_Stadium_Name` (
`stadiumName` varchar(50)
,`teamName` varchar(50)
,`street` varchar(50)
,`city` varchar(50)
,`state` varchar(30)
,`zip` varchar(10)
,`boxOfficeNum` varchar(20)
,`dateOpened` varchar(15)
,`capacity` varchar(50)
,`league` varchar(20)
,`surface` varchar(10)
);
-- --------------------------------------------------------

--
-- Stand-in structure for view `ASC_Team_Name`
--
DROP VIEW IF EXISTS `ASC_Team_Name`;
CREATE TABLE IF NOT EXISTS `ASC_Team_Name` (
`stadiumName` varchar(50)
,`teamName` varchar(50)
,`street` varchar(50)
,`city` varchar(50)
,`state` varchar(30)
,`zip` varchar(10)
,`boxOfficeNum` varchar(20)
,`dateOpened` varchar(15)
,`capacity` varchar(50)
,`league` varchar(20)
,`surface` varchar(10)
);
-- --------------------------------------------------------

--
-- Stand-in structure for view `ASC_Team_Name_Grass_Only`
--
DROP VIEW IF EXISTS `ASC_Team_Name_Grass_Only`;
CREATE TABLE IF NOT EXISTS `ASC_Team_Name_Grass_Only` (
`stadiumName` varchar(50)
,`teamName` varchar(50)
,`street` varchar(50)
,`city` varchar(50)
,`state` varchar(30)
,`zip` varchar(10)
,`boxOfficeNum` varchar(20)
,`dateOpened` varchar(15)
,`capacity` varchar(50)
,`league` varchar(20)
,`surface` varchar(10)
);
-- --------------------------------------------------------

--
-- Table structure for table `Souvenirs`
--

DROP TABLE IF EXISTS `Souvenirs`;
CREATE TABLE IF NOT EXISTS `Souvenirs` (
  `souvenir` varchar(30) DEFAULT NULL,
  `price` decimal(7,2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `Souvenirs`
--

INSERT INTO `Souvenirs` (`souvenir`, `price`) VALUES
('Baseball cap', 25.99),
('Baseball bat', 35.35),
('Team pennant', 12.99),
('Autographed baseball', 19.99);

-- --------------------------------------------------------

--
-- Table structure for table `Stadiums`
--

DROP TABLE IF EXISTS `Stadiums`;
CREATE TABLE IF NOT EXISTS `Stadiums` (
  `stadiumName` varchar(50) DEFAULT NULL,
  `teamName` varchar(50) DEFAULT NULL,
  `street` varchar(50) DEFAULT NULL,
  `city` varchar(50) DEFAULT NULL,
  `state` varchar(30) DEFAULT NULL,
  `zip` varchar(10) DEFAULT NULL,
  `boxOfficeNum` varchar(20) DEFAULT NULL,
  `dateOpened` varchar(15) DEFAULT NULL,
  `capacity` varchar(50) DEFAULT NULL,
  `league` varchar(20) DEFAULT NULL,
  `surface` varchar(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `Stadiums`
--

INSERT INTO `Stadiums` (`stadiumName`, `teamName`, `street`, `city`, `state`, `zip`, `boxOfficeNum`, `dateOpened`, `capacity`, `league`, `surface`) VALUES
('Angels Stadium of Anaheim', 'Los Angeles Angels of Anaheim', '2000 E Gene Autry Way', 'Anaheim', 'CA', '92806', '714-940-2000', '1966-04-19', '45,483', 'American', 'Grass'),
('Comerica Park', 'Detroit Tigers', '2100 Woodward Ave', 'Detroit', 'MI', '48201', '313-962-4000', '2000-04-11', '41,681', 'American', 'Grass'),
('Fenway Park', 'Boston Red Sox', '4 Yawkey Way', 'Boston', 'MA', '02215', '877-733-7699', '1912-04-20', '37,499 (night) & 37,071 (day)', 'American', 'Grass'),
('Globe Life Park in Arlington', 'Texas Rangers', '1000 Ballpark Way', 'Arlington', 'TX', '76011', '817-273-5222', '1994-04-1', '48,114', 'American', 'Grass'),
('Kauffman Stadium', 'Kansas City Royals', '1 Royal Way', 'Kansas City', 'MO', '64129', '816-921-8000', '1973-04-10', '37,903', 'American', 'Grass'),
('Minute Maid Park', 'Houston Astros', '501 Crawford St', 'Houston', 'TX', '77002', '713-259-8000', '2000-03-30', '42,060', 'American', 'Grass'),
('O.co Coliseum', 'Oakland Athletics', '7000 Coliseum Way', 'Oakland', 'CA', '94621', '510-569-2121', '1966-09-18', '37,090 (April - August) & 55,945 (Sept - Jan)', 'American', 'Grass'),
('Oriole Park at Camden Yards', 'Baltimore Orioles', '333 West Camden Street', 'Baltimore', 'MD', '21201', '410-685-9800', '1992-04-6', '48,187', 'American', 'Grass'),
('Progressive Field', 'Cleveland Indians', '2401 Ontario Street', 'Cleveland', 'OH', '44115', '216-420-4487', '1994-04-2', '42,404', 'American', 'Grass'),
('Rogers Centre', 'Toronto Blue Jays', '1 Blue Jays Way', 'Toronto', 'Ontario,Canada', 'M5V1J3', '416-341-1000', '1989-06-3', '49,282', 'American', 'Turf'),
('SafeCo Field', 'Seattle Mariners', '1516 First Avenue South', 'Seattle', 'WA', '98134', '206-346-4000', '1999-07-15', '47,476', 'American', 'Grass'),
('Target Field', 'Minnesota Twins', '353 N 5th St', 'Minneapolis', 'MN', '55403', '800-338-9467', '2010-04-12', '39,021', 'American', 'Grass'),
('Tropicana Field', 'Tampa Bay Rays', '1 Tropicana Dr', 'St. Petersburg', 'FL', '33705', '727-825-3137', '1990-03-3', '31,042 (Regular Season) 42,735 (Postseason)', 'American', 'Turf'),
('US Cellular Field', 'Chicago White Sox', '333 West 35th Street', 'Chicago', 'IL', '60616', '312-674-1000', '1991-04-18', '40,615', 'American', 'Grass'),
('Yankee Stadium', 'New York Yankees', '1 E 161st St', 'South Bronx', 'NY', '10451', '718-293-4300', '2009-04-16', '50,291', 'American', 'Grass'),
('AT&T Park', 'San Francisco Giants', '24 Willie Mays Plaza', 'San Francisco', 'CA', '94107', '415-972-2000', '2000-04-11', '41,915', 'National', 'Grass'),
('Busch Stadium', 'St. Louis Cardinals', '700 Clark Street', 'St. Louis', 'MO', '63102', '314-345-9600', '2006-04-10', '46,861', 'National', 'Grass'),
('Chase Field', 'Arizona Diamondbacks', '401 East Jefferson Street', 'Phoenix', 'AZ', '85004', '602-462-6500', '1998-03-31', '48,633', 'National', 'Grass'),
('Citi Field', 'New York Mets', '126th St. & Roosevelt Ave.', 'Queens', 'NY', '11368', '718-507-6387', '2009-04-13', '41,922', 'National', 'Grass'),
('Citizens Bank Park', 'Philadelphia Phillies', '1 Citizens Bank Way', 'Philadelphia', 'PA', '19148', '215-463-1000', '2004-04-3', '43,651', 'National', 'Grass'),
('Coors Field', 'Colorado Rockies', '2001 Blake St', 'Denver', 'CO', '80205', '303-292-0200', '1995-04-26', '50,480', 'National', 'Grass'),
('Dodger Stadium', 'Los Angeles Dodgers', '1000 Elysian Park Avenue', 'Los Angeles', 'CA', '90090', '323-224-1507', '1962-04-10', '56,000', 'National', 'Grass'),
('Great American Ball Park', 'Cincinnati Reds', '100 Joe Nuxhall Way', 'Cincinnati', 'OH', '45202', '513-381-7337', '2003-03-31', '42,319', 'National', 'Grass'),
('Marlins Park', 'Miami Marlins', '501 Marlins Way', 'Miami', 'FL', '33125', '305-480-1300', '2012-04-4', '37,442', 'National', 'Grass'),
('Miller Park', 'Milwaukee Brewers', '1 Brewers Way', 'Milwaukee', 'WI', '53214', '414-902-4400', '2001-04-6', '41,900', 'National', 'Grass'),
('Nationals Park', 'Washington Nationals', '1500 S Capitol St SE', 'Washington', 'DC', '20003', '202-675-6287', '2008-03-30', '41,418', 'National', 'Grass'),
('Petco Park', 'San Diego Padres', '19 Tony Gwynn Drive', 'San Diego', 'CA', '92101', '619-795-5000', '2004-04-8', '42,524', 'National', 'Grass'),
('PNC Park', 'Pittsburgh Pirates', '115 Federal St', 'Pittsburgh', 'PA', '15212', '412-321-2827', '2001-03-31', '38,362', 'National', 'Grass'),
('Turner Field', 'Atlanta Braves', '755 Hank Aaron Drive', 'Atlanta', 'GA', '30315', '404-522-7630', '1997-03-29', '49,586', 'National', 'Grass'),
('Wrigley Field', 'Chicago Cubs', '1060 West Addison Street', 'Chicago', 'IL', '60613', '773-404-2827', '1914-04-23', '42,374', 'National', 'Grass');

-- --------------------------------------------------------

--
-- Table structure for table `Testing_Table`
--

DROP TABLE IF EXISTS `Testing_Table`;
CREATE TABLE IF NOT EXISTS `Testing_Table` (
  `Column1` int(100) NOT NULL AUTO_INCREMENT,
  `Column2` varchar(255) NOT NULL DEFAULT 'EMPTY',
  PRIMARY KEY (`Column1`),
  KEY `Column1` (`Column1`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=4 ;

--
-- Dumping data for table `Testing_Table`
--

INSERT INTO `Testing_Table` (`Column1`, `Column2`) VALUES
(1, 'String 1!!'),
(2, 'String 2!!!'),
(3, 'TESTING');

-- --------------------------------------------------------

--
-- Structure for view `ASC_American_TeamName`
--
DROP TABLE IF EXISTS `ASC_American_TeamName`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `ASC_American_TeamName` AS select `Stadiums`.`stadiumName` AS `stadiumName`,`Stadiums`.`teamName` AS `teamName`,`Stadiums`.`street` AS `street`,`Stadiums`.`city` AS `city`,`Stadiums`.`state` AS `state`,`Stadiums`.`zip` AS `zip`,`Stadiums`.`boxOfficeNum` AS `boxOfficeNum`,`Stadiums`.`dateOpened` AS `dateOpened`,`Stadiums`.`capacity` AS `capacity`,`Stadiums`.`league` AS `league`,`Stadiums`.`surface` AS `surface` from `Stadiums` where (`Stadiums`.`league` = 'American') order by `Stadiums`.`teamName`;

-- --------------------------------------------------------

--
-- Structure for view `ASC_Date_Opened`
--
DROP TABLE IF EXISTS `ASC_Date_Opened`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `ASC_Date_Opened` AS select `Stadiums`.`stadiumName` AS `stadiumName`,`Stadiums`.`teamName` AS `teamName`,`Stadiums`.`street` AS `street`,`Stadiums`.`city` AS `city`,`Stadiums`.`state` AS `state`,`Stadiums`.`zip` AS `zip`,`Stadiums`.`boxOfficeNum` AS `boxOfficeNum`,`Stadiums`.`dateOpened` AS `dateOpened`,`Stadiums`.`capacity` AS `capacity`,`Stadiums`.`league` AS `league`,`Stadiums`.`surface` AS `surface` from `Stadiums` order by `Stadiums`.`dateOpened`;

-- --------------------------------------------------------

--
-- Structure for view `ASC_National_Team_Name`
--
DROP TABLE IF EXISTS `ASC_National_Team_Name`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `ASC_National_Team_Name` AS select `Stadiums`.`stadiumName` AS `stadiumName`,`Stadiums`.`teamName` AS `teamName`,`Stadiums`.`street` AS `street`,`Stadiums`.`city` AS `city`,`Stadiums`.`state` AS `state`,`Stadiums`.`zip` AS `zip`,`Stadiums`.`boxOfficeNum` AS `boxOfficeNum`,`Stadiums`.`dateOpened` AS `dateOpened`,`Stadiums`.`capacity` AS `capacity`,`Stadiums`.`league` AS `league`,`Stadiums`.`surface` AS `surface` from `Stadiums` where (`Stadiums`.`league` = 'National') order by `Stadiums`.`teamName`;

-- --------------------------------------------------------

--
-- Structure for view `ASC_Stadium_Name`
--
DROP TABLE IF EXISTS `ASC_Stadium_Name`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `ASC_Stadium_Name` AS select `Stadiums`.`stadiumName` AS `stadiumName`,`Stadiums`.`teamName` AS `teamName`,`Stadiums`.`street` AS `street`,`Stadiums`.`city` AS `city`,`Stadiums`.`state` AS `state`,`Stadiums`.`zip` AS `zip`,`Stadiums`.`boxOfficeNum` AS `boxOfficeNum`,`Stadiums`.`dateOpened` AS `dateOpened`,`Stadiums`.`capacity` AS `capacity`,`Stadiums`.`league` AS `league`,`Stadiums`.`surface` AS `surface` from `Stadiums` order by `Stadiums`.`stadiumName`;

-- --------------------------------------------------------

--
-- Structure for view `ASC_Team_Name`
--
DROP TABLE IF EXISTS `ASC_Team_Name`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `ASC_Team_Name` AS select `Stadiums`.`stadiumName` AS `stadiumName`,`Stadiums`.`teamName` AS `teamName`,`Stadiums`.`street` AS `street`,`Stadiums`.`city` AS `city`,`Stadiums`.`state` AS `state`,`Stadiums`.`zip` AS `zip`,`Stadiums`.`boxOfficeNum` AS `boxOfficeNum`,`Stadiums`.`dateOpened` AS `dateOpened`,`Stadiums`.`capacity` AS `capacity`,`Stadiums`.`league` AS `league`,`Stadiums`.`surface` AS `surface` from `Stadiums` order by `Stadiums`.`teamName`;

-- --------------------------------------------------------

--
-- Structure for view `ASC_Team_Name_Grass_Only`
--
DROP TABLE IF EXISTS `ASC_Team_Name_Grass_Only`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `ASC_Team_Name_Grass_Only` AS select `Stadiums`.`stadiumName` AS `stadiumName`,`Stadiums`.`teamName` AS `teamName`,`Stadiums`.`street` AS `street`,`Stadiums`.`city` AS `city`,`Stadiums`.`state` AS `state`,`Stadiums`.`zip` AS `zip`,`Stadiums`.`boxOfficeNum` AS `boxOfficeNum`,`Stadiums`.`dateOpened` AS `dateOpened`,`Stadiums`.`capacity` AS `capacity`,`Stadiums`.`league` AS `league`,`Stadiums`.`surface` AS `surface` from `Stadiums` where (`Stadiums`.`surface` = 'Grass') order by `Stadiums`.`teamName`;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
