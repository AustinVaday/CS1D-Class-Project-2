FLOW = OAuth2WebServerFlow(
	client_id='1936788629-0b4qra0g6s1ea8glhdtipc0vm04dgedi.apps.googleusercontent.com',
	client_secret='e9_yNw2D9GJmWDNvTanGm6hL',
	redirect_uri='https://.../oauth2callback',
	scope='https://.../tasks',
	user_agent='my-sample/1.0'
)

authorize_url = FLOW.step1_get_authorize_url()
self.redirect(authorize_url)

credentials = flow.step2_exchange(self.request.params)
storage = StorageByKeyName(Credentials, user.user_id(), 'credentials')
storage.put(credentials)

user = users.get_current_user()
storage = StorageByKeyName(Credentials, user.user_id(), 'credentials')

credentials = storage.get()

http = httplib2.Http()
http = credentials.authorize(http)
