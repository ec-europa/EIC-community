core = 7.x
api = 2

; Modules related to users.

projects[antibot][subdir] = "contrib"
projects[antibot][version] = "1.2"

projects[campaignmonitor][subdir] = "contrib"
projects[campaignmonitor][version] = "1.1"
; The campaignmonitor module uses an older version of libraries, it also installs it in another location, so then there 2 libraries modules.
projects[campaignmonitor][patch][] = "../patches/campaignmonitor_sync_libraries_module.patch"


projects[email_confirm][subdir] = "contrib"
projects[email_confirm][version] = "1.3"

projects[legal][subdir] = "contrib"
projects[legal][version] = "1.10"

projects[nocurrent_pass][subdir] = "contrib"
projects[nocurrent_pass][version] = "1.1"

projects[user_registrationpassword][subdir] = "contrib"
projects[user_registrationpassword][version] = "1.5"

libraries[campaignmonitor][download][type]= "get"
libraries[campaignmonitor][download][url] = "https://github.com/campaignmonitor/createsend-php/zipball/master"
libraries[campaignmonitor][directory_name] = "campaignmonitor"
libraries[campaignmonitor][destination] = "libraries"
