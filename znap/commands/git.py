import typer
from rich.console import Console
from znap.utils import run_command


console = Console()

class gitCommands:
    def __init__(self, app: typer.Typer):
        self.app = app
        self.register_commands()
    
    def register_commands(self):
        self.app.command()(self.setup)
        self.app.command()(self.init)
        self.app.command()(self.clone) #TODO: same with these too (read below for more details lol)
        self.app.command()(self.add)
        self.app.command()(self.commit) #TODO: same here too, merge we can always use optional arguments hehe
        self.app.command()(self.diff)
        self.app.command()(self.branch)
        self.app.command()(self.checkout) #TODO: this one too, merge it with above two
        self.app.command()(self.log)
        self.app.command()(self.reset)
        self.app.command()(self.stash)
        self.app.command()(self.merge)
        self.app.command()(self.rebase) #TODO: try to merge above three too as line or smtng
        self.app.command()(self.remote) #TODO: Add push pull fetch inside one
        #TODO: Add more commands and please keep the docs clean and super understandable and try to make everything so consise that they should stop using git directly n start using this, lol 
        #!MAKE THIS USEFUL AND EASY AS POSSSIBLE ALSO FAST AF
