import typer
from znap.commands import git, sys

app = typer.Typer()

app.add_typer(git.app, name="git")
app.add_typer(sys.app, name="sys")


if __name__ == "__main__":
    app()