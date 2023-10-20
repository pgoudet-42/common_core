<?php

/** Nom de la base de données de WordPress. */
define( 'DB_NAME', 'wordpress' );

/** Utilisateur de la base de données MySQL. */
define( 'DB_USER', 'root' );

/** Mot de passe de la base de données MySQL. */
define( 'DB_PASSWORD', 'password' );

/** Adresse de l’hébergement MySQL. */
define( 'DB_HOST', 'mysql' );

/** Jeu de caractères à utiliser par la base de données lors de la création des tables. */
define( 'DB_CHARSET', 'utf8' );

/**
 * Type de collation de la base de données.
 * N’y touchez que si vous savez ce que vous faites.
 */
define( 'DB_COLLATE', '' );

/**#@+
 * Clés uniques d’authentification et salage.
 *
 * Remplacez les valeurs par défaut par des phrases uniques !
 * Vous pouvez générer des phrases aléatoires en utilisant
 * {@link https://api.wordpress.org/secret-key/1.1/salt/ le service de clés secrètes de WordPress.org}.
 * Vous pouvez modifier ces phrases à n’importe quel moment, afin d’invalider tous les cookies existants.
 * Cela forcera également tous les utilisateurs à se reconnecter.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         '._|gT[:i~Sfa^$W-^68lwDhErG+iARN,qo9JWVM<?}Nek<A`b{r>Qf5|?uFh6:2)' );
define( 'SECURE_AUTH_KEY',  '%U;z_&8]E3IeIp^mr#Oxnro=4VIe0Puc_o}*Ci{JV}5 &(x2c 4~qGHAK,HdUb+s' );
define( 'LOGGED_IN_KEY',    '-@cQa#ZE>V.MU5?ur}{ku>2j7oGm_u3}~FK[9^?w:.9=E,r%&DP9cf^[M2n={j,<' );
define( 'NONCE_KEY',        'gZy`Vi#NuvlzY<aM{[LB7u7,[tz|H|&^qmH0Y`8lP=BI%M4[c/0[R{z$Sgu+Yn|m' );
define( 'AUTH_SALT',        '2{t]ISKxRN@snT|9>9&BQX|/|-+8XP+Xm#~uz+i?mM+)/tA>#QY|G!]_JyE^Y10-' );
define( 'SECURE_AUTH_SALT', 'W8PZ`py}$sD[XGh3`@3Ha_}]2PdmwXr z*zlRpTlnS#MnA!yHWHIEH`T|pu,)7qU' );
define( 'LOGGED_IN_SALT',   '?J$2U[afu?hZ<V53Mg&WiIPIRqbZuMA&Kfc@*DG4:kztbHF6/-$&5eJ{AK),~fc`' );
define( 'NONCE_SALT',       'ISL?fp|fq=fY5e}-@pH&bs!+/GMXm3zq[(LskV6HATJfAHF3oO!IW*N9X7+;mu}&' );
/**#@-*/

/**
 * Préfixe de base de données pour les tables de WordPress.
 *
 * Vous pouvez installer plusieurs WordPress sur une seule base de données
 * si vous leur donnez chacune un préfixe unique.
 * N’utilisez que des chiffres, des lettres non-accentuées, et des caractères soulignés !
 */
$table_prefix = 'wp_';

/**
 * Pour les développeurs : le mode déboguage de WordPress.
 *
 * En passant la valeur suivante à "true", vous activez l’affichage des
 * notifications d’erreurs pendant vos essais.
 * Il est fortement recommandé que les développeurs d’extensions et
 * de thèmes se servent de WP_DEBUG dans leur environnement de
 * développement.
 *
 * Pour plus d’information sur les autres constantes qui peuvent être utilisées
 * pour le déboguage, rendez-vous sur le Codex.
 *
 * @link https://fr.wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );
define('WP_ALLOW_REPAIR', true);

/* C’est tout, ne touchez pas à ce qui suit ! Bonne publication. */

/** Chemin absolu vers le dossier de WordPress. */
if ( ! defined( 'ABSPATH' ) )
  define( 'ABSPATH', dirname( __FILE__ ) . '/' );

/** Réglage des variables de WordPress et de ses fichiers inclus. */
require_once( ABSPATH . 'wp-settings.php' );