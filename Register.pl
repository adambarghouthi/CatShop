#!/usr/bin/perl
use strict;
use CGI ':standard';

$firstName = param('firstname');
$lastName = param('lastname');
$username = param('username');
$password = param('password');

print "Content-Type: text/html\n\n";
print "<html>\n";
print "<head>\n";
print "<title> CGI/Perl Test </title>\n";
print "</head>\n\n";
print "<body>\n\n";
print "Hello, world!<br><br>\n";
print "Your name: $firstName $lastName<br><br>\n";
print "</body>\n";
print "</html>\n";