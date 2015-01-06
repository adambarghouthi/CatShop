#!/usr/bin/perl
use strict;
use CGI ':standard';

my $q = new CGI;
my $firstName = $q->param('firsname');
my $lastName = $q->param('lastname');
my $username = $q->param('username');
my $password = $q->param('password');

print "Content-Type: text/html\n\n";
print "<html>\n";
print "<head>\n";
print "<title> CGI/Perl Test </title>\n";
print "</head>\n\n";
print "<body>\n\n"

if ($firstName ne '' || $lastName ne '' || $username ne '' || $password ne '') {
	print "Oops! You left one of the fields empty, please fill out all the fields out."
}

elsif ()



print "</body>\n";
print "</html>\n";