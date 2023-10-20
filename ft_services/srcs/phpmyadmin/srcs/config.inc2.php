<?php
/* vim: set expandtab sw=4 ts=4 sts=4: */
/**
 * phpMyAdmin sample configuration, you can use it as base for
 * manual configuration. For easier setup you can use setup/
 *
 * All directives are explained in documentation in the doc/ folder
 * or at <https://docs.phpmyadmin.net/>.
 *
 * @package PhpMyAdmin
 */
declare(strict_types=1);

/**
 * This is needed for cookie based authentication to encrypt password in
 * cookie. Needs to be 32 chars long.
 */
$cfg['blowfish_secret'] = 'IEKiY5{6mOnoEF0LJCL[v8[,USRae0{S';

$vars = array(
	'PMA_HOST',
	'PMA_PORT',
	'PMA_USER',
	'PMA_PASSWORD'
);
	
/**
 * Stock env variables in tab
 */
foreach ($vars as $var) {
	$env = getenv($var);
	if (!isset($_ENV[$var]) && $env !== false) {
		$_ENV[$var] = $env;
	}
}
/**
 * Servers configuration
 */
$i = 0;

/**
 * First server
 */
$i++;
// $cfg['Servers'][$i]['auth_type'] = 'cookie';
// $cfg['Servers'][$i]['host'] = 'mysql';
$cfg['Servers'][$i]['compress'] = false;
$cfg['Servers'][$i]['AllowNoPassword'] = true;
/**
 * phpMyAdmin configuration storage settings.
 */
/**
 * Variable definition
 */
if (!empty($_ENV['PMA_HOST']))
	$cfg['Servers'][$i]['host'] = $_ENV['PMA_HOST'];

if (!empty($_ENV['PMA_PORT']))
	$cfg['Servers'][$i]['port'] = $_ENV['PMA_PORT'];

if (!empty($_ENV['PMA_USER']))
	$cfg['Servers'][$i]['user'] = $_ENV['PMA_USER'];

if (!empty($_ENV['MYSQL_PASSWORD']))
	$cfg['Servers'][$i]['password'] = $_ENV['PMA_PASSWORD'];
/* User used to manipulate with storage */
$cfg['Servers'][$i]['controlhost'] = 'root';
// $cfg['Servers'][$i]['controlport'] = '';
$cfg['Servers'][$i]['controluser'] = $_ENV['PMA_USER'];
$cfg['Servers'][$i]['controlpass'] = $_ENV['PMA_PASSWORD'];

/* Storage database and tables */
$cfg['Servers'][$i]['pmadb'] = 'phpmyadmin';
$cfg['Servers'][$i]['bookmarktable'] = 'pma__bookmark';
$cfg['Servers'][$i]['relation'] = 'pma__relation';
$cfg['Servers'][$i]['table_info'] = 'pma__table_info';
$cfg['Servers'][$i]['table_coords'] = 'pma__table_coords';
$cfg['Servers'][$i]['pdf_pages'] = 'pma__pdf_pages';
$cfg['Servers'][$i]['column_info'] = 'pma__column_info';
$cfg['Servers'][$i]['history'] = 'pma__history';
$cfg['Servers'][$i]['table_uiprefs'] = 'pma__table_uiprefs';
$cfg['Servers'][$i]['tracking'] = 'pma__tracking';
$cfg['Servers'][$i]['userconfig'] = 'pma__userconfig';
$cfg['Servers'][$i]['recent'] = 'pma__recent';
$cfg['Servers'][$i]['favorite'] = 'pma__favorite';
$cfg['Servers'][$i]['users'] = 'pma__users';
$cfg['Servers'][$i]['usergroups'] = 'pma__usergroups';
$cfg['Servers'][$i]['navigationhiding'] = 'pma__navigationhiding';
$cfg['Servers'][$i]['savedsearches'] = 'pma__savedsearches';
$cfg['Servers'][$i]['central_columns'] = 'pma__central_columns';
$cfg['Servers'][$i]['designer_settings'] = 'pma__designer_settings';
$cfg['Servers'][$i]['export_templates'] = 'pma__export_templates';

/**
 * Directories for saving/loading files from server
 */
$cfg['UploadDir'] = '';
$cfg['SaveDir'] = '';