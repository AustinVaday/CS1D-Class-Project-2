#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QErrorMessage>
#include <QDataWidgetMapper>
#include <QModelIndex>
#include <QMessageBox>
#include <QModelIndexList>
#include <fstream>
#include <QTableView>
#include <QTextStream>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow),
    graph(200, UNDIRECTED_GRAPH) // 200 vertices, undirected
{
    this->setWindowTitle("MLB Vacation Planner!");




    //     ui->listWidget_searchResults0->setSelectionMode(QAbstractItemView::MultiSelection);
	vector<Vertex<stadium> *> shortestPath;
	//	float totalCost = 0;
	quickTrip  = false;
	ui->setupUi(this);
	currentStadiumIndex = -1;

	// Create Database and initialize the table model ( NOT VIEW )
    createConnection(true);		// put true to reinitialize the model

	initModel = new QSqlTableModel(0,db);
	souvenirModel = new QSqlTableModel(0,db);
	cartModel = new QSqlTableModel(0,db);

	initializeModel(initModel); // Pass in false if you want to make it only editable when submit is clicked.
	initializeSouvenir(souvenirModel);
	initializeShoppingCart(cartModel);

	ui->tableView_shoppingCart->setModel(souvenirModel);
	ui->tableView_shoppingCart->setSortingEnabled(true);

	ui->tableView_stadiumList->setModel(initModel);
	ui->tableView_stadiumList->setSortingEnabled(true);

	ui->tableView_stadiumList->hideColumn(0);

	fillGraph();

    // Assign all stadium images
    (stadiumHash["AT&T Park"]).setImgPath(":/logos/SanFrancisco.jpg");
    (stadiumHash["Angels Stadium of Anaheim"]).setImgPath(":/logos/LosAngelesAngels.jpg");
    (stadiumHash["Busch Stadium"]).setImgPath(":/logos/Seattle.jpg");
    (stadiumHash["Chase Field"]).setImgPath(":/logos/Arizona.jpg");
    (stadiumHash["Citi Field"]).setImgPath(":/logos/NewYorkMets.jpg");
    (stadiumHash["Citizens Bank Park"]).setImgPath(":/logos/Philadelphia.jpg");
    (stadiumHash["Comerica Park"]).setImgPath(":/logos/Detroit.jpg");
    (stadiumHash["Coors Field"]).setImgPath(":/logos/Colorado.jpg");
    (stadiumHash["Dodger Stadium"]).setImgPath(":/logos/LosAngelesDodgers.jpg");
    (stadiumHash["Fenway Park"]).setImgPath(":/logos/Boston.jpg");
    (stadiumHash["Globe Life Park in Arlington"]).setImgPath(":/logos/TexasRangers.jpg");
    (stadiumHash["Great American Ball Park"]).setImgPath(":/logos/Cincinnati.jpg");
    (stadiumHash["Kauffman Stadium"]).setImgPath(":/logos/KansasCity.jpg");
    (stadiumHash["Marlins Park"]).setImgPath(":/logos/Miami.jpg");
    (stadiumHash["Miller Park"]).setImgPath(":/logos/Milwaukee.jpg");
    (stadiumHash["Minute Maid Park"]).setImgPath(":/logos/Houston.jpg");
    (stadiumHash["Nationals Park"]).setImgPath(":/logos/Washington.jpg");
    (stadiumHash["O.co Coliseum"]).setImgPath(":/logos/Oakland.jpg");
    (stadiumHash["Oriole Park at Camden Yards"]).setImgPath(":/logos/Baltimore.jpg");
    (stadiumHash["PNC Park"]).setImgPath(":/logos/Pittsburgh.jpg");
    (stadiumHash["Petco Park"]).setImgPath(":/logos/SanDiego.jpg");
    (stadiumHash["Progressive Field"]).setImgPath(":/logos/Cleveland.jpg");
    (stadiumHash["Rogers Centre"]).setImgPath(":/logos/Toronto.jpg");
    (stadiumHash["SafeCo Field"]).setImgPath(":/logos/Seattle.jpg");
    (stadiumHash["Target Field"]).setImgPath(":/logos/Minnesota.jpg");
    (stadiumHash["Tropicana Field"]).setImgPath(":/logos/TampaBay.jpg");
    (stadiumHash["Turner Field"]).setImgPath(":/logos/Atlanta.jpg");
    (stadiumHash["US Cellular Field"]).setImgPath(":/logos/ChicagoWSox.jpg");
    (stadiumHash["Wrigley Field"]).setImgPath(":/logos/ChicagoCubs.jpg");
    (stadiumHash["Yankee Stadium"]).setImgPath(":/logos/NewYorkYankees.jpg");

    // Fill out the theme list of background images!
//    themeList.push_back(":/background1.jpg");
    themeList.push_back(":/background2.jpg");
//    themeList.push_back(":/background3.jpg");
    themeList.push_back(":/background4.jpg");
//    themeList.push_back(":/background5.png");
    themeList.push_back(":/background6.jpg");
//    themeList.push_back(":/background7.jpg");
//    themeList.push_back(":/background8.jpg");
    themeList.push_back(":/background9.jpg");
    themeList.push_back(":/background10.png");
//    themeList.push_back(":/background11.jpg");
//    themeList.push_back(":/background12.jpg");
    themeList.push_back(":/background13.png");
    themeList.push_back(":/background15.jpg");
    themeList.push_back(":/background16.jpg");
    themeList.push_back(":/background14.jpg");






	//Initializations of fonts for line edits, etc...
	QFont titleFont;
	titleFont.setPointSize(15);
	titleFont.setBold(true);
	titleFont.setItalic(true);

	ui->label_titleMainMenu->setFont(titleFont);
	ui->label_adminLoginTitle->setFont(titleFont);
//	ui->label_planATripTitle->setFont(titleFont);
	ui->label_teamSearchTitle->setFont(titleFont);
	ui->label_stadiumListTitle->setFont(titleFont);
	ui->label_shopTitle->setFont(titleFont);

    // setup ui
	ui->stackedWidget_mainWidget->currentWidget()->hide();
	ui->page_mainMenu->show();
	ui->stackedWidget_mainWidget->show();

	// Input mask gives type of input allowed for credit card number
	ui->lineEdit_creditCardNumber->setInputMask("0000000000000000");
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_button_back0_clicked()
{
	refresh();
	ui->page_planATrip0->hide();
	ui->page_mainMenu->show();
}

void MainWindow::on_button_planATrip0_clicked()
{
	refresh();
	ui->page_mainMenu->hide();
	ui->page_planATrip0->show();
}

void MainWindow::on_button_searchForStadiums0_clicked()
{

	refresh();

	QStringList * stringList;

	stringList = new QStringList;

	*stringList  << "AT&T Park"
				 << "Angels Stadium of Anaheim"
				 << "Busch Stadium"
				 << "Chase Field"
				 << "Citi Field"
				 << "Citizens Bank Park"
				 << "Comerica Park"
				 << "Coors Feild"
				 << "Dodger Stadium"
				 << "Fenway Park"
				 << "Globe Life Park in Arlington"
				 << " Great American Ball Park"
				 << "Kauffman Stadium"
				 << "Marlins Park"
				 << "Miller Park"
				 << "Minute Maid Park"
				 << "Nationals Park"
				 << "O.co Coliseum"
				 << "Oriole Park at Camden Yards"
				 << "PNC Park"
				 << "Petco Parrk"
				 << "Progressive Field"
				 << "Rogers Centre"
				 << "SafeCo Field"
				 << "Target Field"
				 << "Tropicana Field"
				 << "Turner Field"
				 << "US Cellular Field"
				 << "Wrigley Field"
				 << "Yankee Stadium";


	QCompleter* completer = new QCompleter(*stringList);
	ui->lineEdit_searchLine0->setCompleter(completer);
	ui->page_mainMenu->hide();
	ui->page_searchForStadium0->show();
}

void MainWindow::on_button_mainMenu0_clicked()
{
	refresh();
	ui->page_planATrip0->hide();
	ui->page_mainMenu->show();
}

void MainWindow::on_button_mainMenu2_clicked()
{
	refresh();
	ui->page_searchForStadium0->hide();
	ui->page_mainMenu->show();
}

void MainWindow::on_button_back2_clicked()
{
	refresh();
	ui->page_searchForStadium0->hide();
	ui->page_mainMenu->show();
}

void MainWindow::on_button_mainMenu3_clicked()
{
	refresh();
	ui->page_shop0->hide();
	ui->page_mainMenu->show();
}

void MainWindow::on_button_back3_clicked()
{
	refresh();

	ui->page_shop0->hide();
	ui->page_mainMenu->show();

}

void MainWindow::on_button_mainMenu4_clicked()
{
	refresh();
	ui->page_stadiumList->hide();
	ui->page_mainMenu->show();
}

void MainWindow::on_button_back4_clicked()
{
	refresh();
	ui->page_stadiumList->hide();
	ui->page_mainMenu->show();
}

void MainWindow::on_button_viewStadiums_clicked()
{
	//	QDataWidgetMapper *mapper = new QDataWidgetMapper(initModel);

	//	QTableView *view = createView(initModel, "Stadiums");
	//	view->show();
	ui->tableView_stadiumList->show();
	ui->page_mainMenu->hide();
	ui->page_stadiumList->show();
	refresh();
}

void MainWindow::on_button_shop0_clicked()
{
	refresh();
	//	QTableView* view = createView(model, "Stadiums");
	ui->page_mainMenu->hide();
	ui->page_shop0->show();
}

void MainWindow::on_button_adminAccess0_clicked()
{
	refresh();
	ui->page_mainMenu->hide();
	ui->page_adminLogin0->show();
}

void MainWindow::on_button_mainMenu5_clicked()
{
	ui->page_adminLogin0->hide();
	ui->page_mainMenu->show();
}

void MainWindow::on_button_login_clicked()
{
	//Login button pushed
    QString username      = "admin";
    QString password      = "password";
	QString inputName     = ui->lineEdit_username->text();
	QString inputPassword = ui->lineEdit_password->text();
	if(inputName != username || inputPassword != password)
	{
		QMessageBox::information(this, "Login Error", "incorrect Username or Password");
		ui->lineEdit_password->clear();
		ui->lineEdit_username->clear();
	}
	else
	{
		//qDebug() << "Set name in admin: " << setStadiumName;
		ui->page_adminLogin0->hide();
		ui->page_adminMainMenu->show();
		ui->lineEdit_username->clear();
		ui->lineEdit_password->clear();
	}

}

void MainWindow::on_button_back_adminMainMenu_clicked()
{
	ui->page_adminMainMenu->hide();
	ui->page_adminLogin0->show();
}


void MainWindow::on_button_backAddStadium_clicked()
{
	ui->page_addStadium->hide();
	ui->page_adminMainMenu->show();
}

void MainWindow::on_button_addStadium0_clicked()
{

	// add in all stadiums to combobox
	for (stadiumIt = stadiumHash.begin(); stadiumIt != stadiumHash.end(); stadiumIt++)
	{
		if (!(*stadiumIt).getStadiumName().isEmpty())
		{
			ui->comboBox_adjacentList->addItem((*stadiumIt).getStadiumName());
		}
	}

	ui->page_adminMainMenu->hide();
	ui->page_addStadium->show();
}
void MainWindow::fillGraph()
{
	qDebug() << "filling out the graph...";



	QSqlQuery query = QSqlQuery(db);
	//    QString dbString;
	vector<vertexEdgeStruct> vertexEdgeVector;
	vector<vertexEdgeStruct>::iterator structIt;
	vertexEdgeStruct tempStruct;
	//    QString vertexString1;
	QString vertexString2;
	QString edgeString;
	QStringList stringList;
	QStringList tempStringList;

	// for stadium -- others
	int stadiumNum;
	QString stadiumName;
	QString teamName;
	QString street;
	QString city;
	QString state;
	int zip;
	QString boxOfficeNum;
	QString dateOpened;
	QString capacity;
	QString league;
	QString surface;
	QString verticesAndEdges;

	stadium *stadiumObj;

	query.exec("SELECT * FROM stadiums");


	// retrieve all stadium
	while (query.next())
	{
		stadiumNum      = query.value(PRIMARY_KEY).toInt();
		stadiumName     = query.value(STADIUM_NAME).toString();
		teamName        = query.value(TEAM_NAME).toString();
		street          = query.value(STREET).toString();
		city            = query.value(CITY).toString();
		state           = query.value(STATE).toString();
		zip             = query.value(ZIP).toInt();
		boxOfficeNum    = query.value(BOX_OFFICE_NUM).toString();
		dateOpened      = query.value(DATE_OPENED).toString();
		capacity        = query.value(CAPACITY).toString();
		league          = query.value(LEAGUE).toString();
		surface         = query.value(SURFACE).toString();
		verticesAndEdges= query.value(VERTICES_AND_EDGES).toString();


		// list of strings split by ~ (vertex,edge pair)
		stringList = verticesAndEdges.split('~');

		for (int i = 0; i < stringList.size(); i++)
		{
			// split vertex-edge pair by delimter ';'
			tempStringList = (stringList[i].split(';'));
			// first entry is a vertex
			vertexString2 = tempStringList[0];
			// second entry is an edge
			edgeString = tempStringList[1];
			tempStruct.otherVertex = vertexString2;
			tempStruct.edge = edgeString.toFloat();
			vertexEdgeVector.push_back(tempStruct);
			tempStringList.clear();
		}

		// create stadium
		stadiumObj = new stadium ( stadiumNum,
								   stadiumName,
								   teamName,
								   street,
								   city,
								   state,
								   zip,
								   boxOfficeNum,
								   dateOpened,
								   capacity,
								   league,
								   surface,
								   vertexEdgeVector
								   );

		// push back an object (force a pass by copy)
		//        stadiumHash.insert(stadium(*stadiumObj), stadiumName);
		stadiumHash.insert(stadiumName,  stadium(*stadiumObj));

		// delete stadium object
		delete stadiumObj;

		vertexEdgeVector.clear();

	}



	//    // create all stadium objects

	//    /****************************************
	//     *  Temp -- dummy data
	//     * *************************************/
	//    stadium stadiumDummyArray[10];

	//    //fill out stadium name and
	//    for (int i = 0; i < 10; i++)
	//    {

	//        stadiumDummyArray[i].setStadiumName("SEE STADIUM NUM INSTEAD!");
	//        stadiumDummyArray[i].setStadiumNumber(i);

	//    }


	// add all stadium objects to graph

	QMap<QString,stadium>::iterator stadiumIt;
	QMap<QString,stadium>::iterator otherStadiumIt;

	float weight;
	QString otherStadium;

	// re-use the following datatypes
	stadiumName.clear();

	int i = 0;
	qDebug() << "FILL IN: ";
	for (stadiumIt = stadiumHash.begin(); stadiumIt != stadiumHash.end(); stadiumIt++)
	{
		i++;
		qDebug() << "Stadium " << i << " is " << (*stadiumIt).getStadiumName();

	}

	for (stadiumIt = stadiumHash.begin(); stadiumIt != stadiumHash.end(); stadiumIt++)
	{

		vertexEdgeVector.clear();

		vertexEdgeVector = (*stadiumIt).getVertexEdgeStructVector();

		stadiumName = (*stadiumIt).getStadiumName();

		for (unsigned int i = 0; i < vertexEdgeVector.size(); i++)
		{
			otherStadium = (vertexEdgeVector[i]).otherVertex;
			weight = (vertexEdgeVector[i]).edge;

			if (!otherStadium.isEmpty())
			{
				if (stadiumHash.contains(otherStadium))
				{
					otherStadiumIt = stadiumHash.find(otherStadium);
					graph.insert((*stadiumIt), *otherStadiumIt, weight);

				}
				else
				{
					qDebug() << "Other Stadium not found: " << otherStadium;
				}

			}
		}



	}

	i = 0;
	qDebug() << "FILL IN: ";
	for (stadiumIt = stadiumHash.begin(); stadiumIt != stadiumHash.end(); stadiumIt++)
	{
		i++;
		qDebug() << "Stadium " << i << " is " << (*stadiumIt).getStadiumName();

	}
	qDebug() << "Stadium hash size: " << stadiumHash.size();
	//    graph.display();


}
/***********************************************************************************************************************************************
 * ***************************************




******************************************************************************************************
 * *********************************************************************************************************************************************
 ***********************************************************************************************************************************************
  **********************************************************************************************************************************************
 ***********************************************************************************************************************************************
 ***********************************************************************************************************************************************
 ***********************************************************************************************************************************************
 ** LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE **
 **  ** LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE **
	**  ** LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE **
		**  ** LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE **
				** LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE **
			** LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE **
		** LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE **
	 ** LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE **
	** LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE **
** LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE <<>>> LOST CODE ***/
//    // add in all stadiums to combobox
//    for (stadiumIt = stadiumHash.begin(); stadiumIt != stadiumHash.end(); stadiumIt++)
//    {
//        if (!(*stadiumIt).getStadiumName().isEmpty())
//        {
//            Ui->comboBox_adjacentList->addItem((*stadiumIt).getStadiumName());
//        }
//    }


//    ui->page_adminMainMenu->hide();
//    ui->page_addStadium->show();


/***********************************************************************************************************************************************
 * *********************************************************************************************************************************************
 * *********************************************************************************************************************************************
 ***********************************************************************************************************************************************
  **********************************************************************************************************************************************
 ***********************************************************************************************************************************************
 ***********************************************************************************************************************************************
 ***********************************************************************************************************************************************/

void MainWindow::on_button_quickTrip0_clicked()
{
	ui->page_planATrip0->hide();
	ui->page_quickTripMenu->show();

	ui->comboBox_quickTripSelectStadium->clear();

	// add in all stadiums to combobox
	for (stadiumIt = stadiumHash.begin(); stadiumIt != stadiumHash.end(); stadiumIt++)
	{
		if (!(*stadiumIt).getStadiumName().isEmpty())
		{
			ui->comboBox_quickTripSelectStadium->addItem((*stadiumIt).getStadiumName());
		}
	}
}

void MainWindow::on_button_confirm_clicked()
{
	// Clear label errors
	ui->label_errorName->setText("");
	ui->label_errorCardNumber->setText("");

	// Check for any errors
	if (ui->lineEdit_name->text() == "" || ui->lineEdit_creditCardNumber->text() == "")
	{
		// Determine which errors exist and display error message
		if (ui->lineEdit_name->text() == "")
		{
			ui->label_errorName->setText("Please enter a valid name.");
		}
		if (ui->lineEdit_creditCardNumber->text().length() != 16)
		{
			ui->label_errorCardNumber->setText("Please enter a valid 16-digit credit card number.");
		}
	}
	else
	{
		QMessageBox::information(this, tr("Confirm Order"), tr("Thank you for shopping with us. Your order has been placed."));
		ui->page_shoppingCart->hide();
		ui->page_shop0->show();
	}
}

void MainWindow::on_button_cancel_clicked()
{
	QMessageBox::information(this, tr("Cancel Order"), tr("Your order has been canceled."));
	ui->page_shoppingCart->hide();
    ui->page_mainMenu->show();
}

void MainWindow::on_button_finish_clicked()
{
	// Clear label errors
	ui->label_errorName->setText("");
	ui->label_errorCardNumber->setText("");

	refresh();
	ui->page_shop0->hide();
    ui->page_mainMenu->show();
}
void MainWindow::on_button_customTrip0_clicked()
{
	ui->page_planATrip0->hide();
	ui->page_customTripMenu->show();

	ui->comboBox_customTripSelectStadium->clear();
	ui->listWidget_customTrip->clear();


	QListWidgetItem *listItem;
	// add in all stadiums to combobox and QListWidget
	for (stadiumIt = stadiumHash.begin(); stadiumIt != stadiumHash.end(); stadiumIt++)
	{
		if (!(*stadiumIt).getStadiumName().isEmpty())
		{
			ui->comboBox_customTripSelectStadium->addItem((*stadiumIt).getStadiumName());

			listItem = new QListWidgetItem;
			listItem->setFlags(listItem->flags() | Qt::ItemIsUserCheckable);
			listItem->setCheckState(Qt::Unchecked);
			listItem->setText((*stadiumIt).getStadiumName());

			ui->listWidget_customTrip->addItem(listItem);
		}
	}
}


void MainWindow::on_pushButton_customTripGo_clicked()
{
	QString startStadium = ui->comboBox_customTripSelectStadium->currentText();
	vector<QString> selectedStadiums;
	float cost = 0;
	float totalCost = 0;

	vector<Vertex<stadium> *> subsequentVertexVector;
	vector<Vertex<stadium> *>::iterator vertexVecIt;
	dijkstraVertexVector.clear();
	currentStadiumIndex = -1;

	// push back starting stadium
	selectedStadiums.push_back(startStadium);

	// retrieve all selected stadiums
	QListWidgetItem *currentItem;
	for (int i = 0; i < stadiumHash.size(); i++)
	{
		currentItem = ui->listWidget_customTrip->item(i);
		if (currentItem->checkState() == Qt::Checked)
		{
			selectedStadiums.push_back(currentItem->text());
		}


	}
	// User must select at least one stadium (the stadium currently inside is the starting stadium, it's always there)
	if (selectedStadiums.size() == 1)
	{
		QMessageBox::information(this, "Error.", "Please select at least ONE designated stadium.");
	}
	else
	{
		// loop until stadium before last selected stadium is reached (need i+1)
		for (unsigned int i = 0; i < selectedStadiums.size() - 1; i++)
		{
			subsequentVertexVector.clear();

			graph.DijkstraShortestPath(*(stadiumHash.find(selectedStadiums[i])), *(stadiumHash.find(selectedStadiums[i + 1])), subsequentVertexVector, cost);

			qDebug() << "Cost is: " << cost;
			totalCost = totalCost + cost;
			qDebug() << "Total cost is: " << totalCost;


			for (unsigned int j = 0; j < subsequentVertexVector.size(); j++)
			{
				dijkstraVertexVector.push_back(subsequentVertexVector[j]);

				//                if ( j != 0)
				//                {
				//                    // prevent subsequent duplicates by seeing if stadiums entered in twice
				//                    if (**(subsequentVertexVector[j]) == **(subsequentVertexVector[j-1]))
				//                    {
				//                        dijkstraVertexVector.pop_back();
				//                    }
				//                }

			}

			// update new current stadium
			//            startStadium = selectedStadiums[i];
		}


		// remove duplicates in dijkstraVertexVector ...
		for (vertexVecIt = dijkstraVertexVector.begin();
			 vertexVecIt != dijkstraVertexVector.end();
			 vertexVecIt++)
		{

			if (vertexVecIt + 1 != dijkstraVertexVector.end())
			{
				qDebug() << "Comparing " << ***vertexVecIt << " and " << ***(vertexVecIt + 1);
				// prevent subsequent duplicates by seeing if stadiums entered in twice
				if (***(vertexVecIt) == ***(vertexVecIt + 1))
				{
					dijkstraVertexVector.erase(vertexVecIt);
					qDebug() << "Erasing " << (***vertexVecIt).getStadiumName();
				}

			}

		}

		// fill out QListWidget with dijkstra sequence.
		QListWidgetItem *listItem;

		ui->listWidget_customTripSequence->clear();


		for (unsigned int i = 0; i < dijkstraVertexVector.size(); i++)
		{

			listItem = new QListWidgetItem;
			listItem->setText((**(dijkstraVertexVector[i])).getStadiumName());
			listItem->setFlags(Qt::ItemIsEditable & !Qt::ItemIsSelectable );
			// indicate first one is current stadium
			if (i == 0)
			{
				currentStadiumIndex = 0;
				listItem->setTextColor(QColor("red"));
				listItem->setFont(QFont("bold"));

				ui->label_customTripStadiumName->setText(listItem->text());
				ui->pushButton_customTripPrevious->setEnabled(false);
				ui->pushButton_customTripNext->setEnabled(false);

                // SET first team image
                QString imgPath = stadiumHash[listItem->text()].getStadiumImagePath();
                QString styleString = "image: url(" + imgPath + ");";
                ui->imageWidget->setStyleSheet(styleString);
                ui->imageWidget->setStyleSheet(styleString);
                ui->imageWidget->update();

            }
			else
			{
				ui->pushButton_customTripNext->setEnabled(true);

				listItem->setTextColor(QColor("gray"));
			}
			ui->listWidget_customTripSequence->addItem(listItem);
		}
		//=======

		//                ui->label_customTripStadiumName->setText(listItem->text());
		//                ui->pushButton_customTripPrevious->setEnabled(false);
		//                ui->pushButton_customTripNext->setEnabled(false);
		//>>>>>>> 461570e42d0013ccc2ba65c042568830384f004c

		ui->label_customTripDistanceTravelled->setText(QString::number(totalCost) + " miles.");

		// set the value of the progress bar.
		SetProgressBar(-1);

		ui->page_customTripMenu->hide();
		ui->page_customTrip->show();
	}
}

void MainWindow::on_button_customTripBack_clicked()
{
	ui->page_customTripMenu->hide();
	ui->page_planATrip0->show();
}

void MainWindow::on_button_customTripMainMenu_clicked()
{
	ui->page_customTripMenu->hide();
	ui->page_mainMenu->show();
}

void MainWindow::on_button_customTripBack_2_clicked()
{
	ui->page_customTrip->hide();

	if (quickTrip)
	{
		ui->page_quickTripMenu->show();
		quickTrip = false;
	}
	else
	{
		ui->page_customTripMenu->show();
	}
}

void MainWindow::on_button_customTripMainMenu_2_clicked()
{
	ui->page_customTrip->hide();
	ui->page_mainMenu->show();
}

void MainWindow::on_pushButton_customTripNext_clicked()
{
	QListWidgetItem *listItem;
	//    stadium *currentStadium;

	if (currentStadiumIndex == -1)
	{
		QMessageBox::information(this, "ERROR - on_pushButton_customTripNext_clicked()", "error");
	}

	// check if we're at last stadium --> disable the next button
	if (currentStadiumIndex + 1 == int(dijkstraVertexVector.size() - 1))
	{
		ui->pushButton_customTripNext->setEnabled(false);
	}
	else
	{
		ui->pushButton_customTripNext->setEnabled(true);

	}

	// enable previous button
	if (currentStadiumIndex == 0)
	{
		ui->pushButton_customTripPrevious->setEnabled(true);

	}

	// set the old QListWidgetItem back to default
	listItem = ui->listWidget_customTripSequence->item(currentStadiumIndex);
	listItem->setTextColor(QColor("gray"));
	listItem->setFont(QFont("none"));

	currentStadiumIndex++;

	// set the current QListWidgetItem to current stadium indicator
	listItem = ui->listWidget_customTripSequence->item(currentStadiumIndex);
	listItem->setTextColor(QColor("red"));
	listItem->setFont(QFont("bold"));

	//    currentStadium = stadiumHash.find(listItem->text());

	ui->label_customTripStadiumName->setText(listItem->text());
	on_label_customTripStadiumName_windowIconTextChanged(listItem->text());

    // SET the team image
    QString styleString = "image: url(" + stadiumHash[listItem->text()].getStadiumImagePath() + ");";
    qDebug() << "STYLESTIRNG IS: " << styleString;
    ui->imageWidget->setStyleSheet(styleString);
    ui->imageWidget->update();

	// update progress bar
	SetProgressBar(currentStadiumIndex);
}

void MainWindow::on_pushButton_customTripPrevious_clicked()
{
	QListWidgetItem *listItem;
	//    stadium *currentStadium;

	if (currentStadiumIndex == -1)
	{
		QMessageBox::information(this, "ERROR - on_pushButton_customTripNext_clicked()", "error");
	}


	// check if we're at first stadium --> disable the previous button
	if (currentStadiumIndex - 1 == 0)
	{
		ui->pushButton_customTripPrevious->setEnabled(false);
	}
	else
	{
		ui->pushButton_customTripPrevious->setEnabled(true);
	}


	// enable the next button if necessary
	if(currentStadiumIndex == int(dijkstraVertexVector.size() - 1))
	{
		ui->pushButton_customTripNext->setEnabled(true);
	}

	// set the old QListWidgetItem back to default
	listItem = ui->listWidget_customTripSequence->item(currentStadiumIndex);
	listItem->setTextColor(QColor("gray"));
	listItem->setFont(QFont("none"));

	currentStadiumIndex--;

	// set the current QListWidgetItem to current stadium indicator
	listItem = ui->listWidget_customTripSequence->item(currentStadiumIndex);
	listItem->setTextColor(QColor("red"));
	listItem->setFont(QFont("bold"));

	//    currentStadium = stadiumHash.find(listItem->text());

	ui->label_customTripStadiumName->setText(listItem->text());

    // SET first team image
    QString styleString = "image: url(" + stadiumHash[listItem->text()].getStadiumImagePath() + ");";
    qDebug() << "STYLESTIRNG IS: " << styleString;
    ui->imageWidget->setStyleSheet(styleString);
    ui->imageWidget->update();

	// update progress bar
	// if back to first, set progress bar blank
	if (currentStadiumIndex == 0)
	{
		SetProgressBar(-1);
	}
	else
	{
		SetProgressBar(currentStadiumIndex);

	}
}

void MainWindow::SetProgressBar(int location)
{
	int progressBarVal = ((float(location + 1)) / dijkstraVertexVector.size()) * 100;
	ui->progressBar_customTrip->setValue(progressBarVal);

}

void MainWindow::on_button_quickTripBack_clicked()
{
	ui->page_quickTripMenu->hide();
	ui->page_planATrip0->show();
}

void MainWindow::on_button_quickTripMainMenu_clicked()
{
	ui->page_quickTripMenu->hide();
	ui->page_mainMenu->show();
}

void MainWindow::on_pushButton_quickTripGo_clicked()
{
    //***
	QString selectedStadium = ui->comboBox_quickTripSelectStadium->currentText();
	float totalCost = 0;

	dijkstraVertexVector.clear();
	currentStadiumIndex = -1;

	graph.DijkstraShortestPath(*(stadiumHash.find("Angels Stadium of Anaheim")), *(stadiumHash.find(selectedStadium)), dijkstraVertexVector, totalCost);

	// fill out QListWidget with dijkstra sequence.
	QListWidgetItem *listItem;

	ui->listWidget_customTripSequence->clear();

	for (unsigned int i = 0; i < dijkstraVertexVector.size(); i++)
	{
		listItem = new QListWidgetItem;
		listItem->setText((**(dijkstraVertexVector[i])).getStadiumName());
		listItem->setFlags(listItem->flags() & Qt::ItemIsEditable & Qt::ItemIsSelectable);

		// indicate first one is current stadium
		if (i == 0)
		{
			currentStadiumIndex = 0;
			listItem->setTextColor(QColor("red"));
			listItem->setFont(QFont("bold"));

			ui->label_customTripStadiumName->setText(listItem->text());

			ui->pushButton_customTripPrevious->setEnabled(false);
			ui->pushButton_customTripNext->setEnabled(false);

            // SET first team image
            QString imgPath = stadiumHash[listItem->text()].getStadiumImagePath();
            QString styleString = "image: url(" + imgPath + ");";
            ui->imageWidget->setStyleSheet(styleString);
            ui->imageWidget->setStyleSheet(styleString);
            ui->imageWidget->update();

		}
		else
		{
			ui->pushButton_customTripNext->setEnabled(true);

			listItem->setTextColor(QColor("gray"));
		}

		ui->listWidget_customTripSequence->addItem(listItem);
	}

	ui->label_customTripDistanceTravelled->setText(QString::number(totalCost) + " miles.");

	// set the value of the progress bar.
	SetProgressBar(-1);

	quickTrip = true;

	ui->page_quickTripMenu->hide();
	ui->page_customTrip->show();

}
void MainWindow::on_button_MST_clicked()
{
	ui->page_planATrip0->hide();
	ui->page_MST->show();

	mstEdgeVector.clear();

	//    QListWidgetItem *listItem;
	QTableWidgetItem *tableItem;


	QString stadium1String;
	QString stadium2String;
	float weight = 0;
	float totalCost = 0;


	graph.MST(mstEdgeVector, totalCost);

	// fill out QListWidget with MST sequence.
	ui->tableWidget_displayMST->setColumnCount(4);

	// add column headers (not working)
	//    ui->tableWidget_displayMST->setHorizontalHeaderLabels(QStringList() << "Switch.." << "Parameter..." << " " << " asd");
	//    ui->tableWidget_displayMST->setHorizontalHeaderItem(0, new QTableWidgetItem("Prueba"));

	//    ui->listWidget_displayMST->clear();
	ui->tableWidget_displayMST->clear();
	for (unsigned int i = 0; i < mstEdgeVector.size(); i++)
	{

		stadium1String = (**((*(mstEdgeVector[i])).getVertex1())).getStadiumName();
		stadium2String = (**((*(mstEdgeVector[i])).getVertex2())).getStadiumName();
		weight =         (*(mstEdgeVector[i])).getWeight();

		//        listItem = new QListWidgetItem;

		ui->tableWidget_displayMST->insertRow(i);

		tableItem = new QTableWidgetItem;
		tableItem->setText(stadium1String);
		tableItem->setFlags(!Qt::ItemIsEditable & Qt::ItemIsSelectable );
		ui->tableWidget_displayMST->setItem(i, 0, tableItem);

		tableItem = new QTableWidgetItem;
		tableItem->setText("       --> ");
		tableItem->setFlags(!Qt::ItemIsEditable & Qt::ItemIsSelectable );
		ui->tableWidget_displayMST->setItem(i, 1, tableItem);

		tableItem = new QTableWidgetItem;
		tableItem->setText(stadium2String);
		tableItem->setFlags(!Qt::ItemIsEditable & Qt::ItemIsSelectable );
		ui->tableWidget_displayMST->setItem(i, 2, tableItem);

		tableItem = new QTableWidgetItem;
		tableItem->setText(QString::number(weight));
		tableItem->setFlags(!Qt::ItemIsEditable & Qt::ItemIsSelectable );
		ui->tableWidget_displayMST->setItem(i, 3, tableItem);



		//        listItem->setText(stadium1String + " --> " + stadium2String + " with weight: " + QString::number(weight));


		//        listItem->setFlags(!Qt::ItemIsEditable & !Qt::ItemIsSelectable );

		//        ui->listWidget_displayMST->addItem(listItem);

	}

	ui->label_MSTDistanceTravelled->setText(QString::number(totalCost) + " miles.");
}

void MainWindow::on_button_backMST_clicked()
{
	ui->page_MST->hide();
	ui->page_planATrip0->show();
}
//****************())************************************************************************
void MainWindow::on_button_backMainMenuMST_clicked()
{
	ui->page_MST->hide();
	ui->page_mainMenu->show();
}


//void MainWindow::on_button_search0_clicked()
//{
//	QFont * newFont;
//	  QLabel * newLabel;
//	  QModelIndexList listIndeces = ui->listWidget_searchResults0->selectionModel()->selectedIndexes();
//	  int rowIndex ;
//	  vector<QString> displayList;
//	  vector<QString>::iterator it;

//	  if(ui->lineEdit_searchLine0->text().isEmpty())
//	  {
//		  QMessageBox::information(this, "Error", "Please enter a search item in the search bar");
//	  }
//	  else
//	  {
//		  ui->listWidget_searchResults0->clear();

//		  displayList = searchForStadium(ui->lineEdit_searchLine0->text().toStdString());

//		  qDebug() << "After Search Stadium";



//		   for(it = displayList.begin(); it != displayList.end(); it++)
//		   {
//			   ui->listWidget_searchResults0->addItem((*it)+ "\n");
//		   }

//	 }


void MainWindow::on_pushButton_clicked()
{

	ui->page_customTrip->hide();
	cartModel->clear();
	cartModel = souvenirModel;
	cartModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
	cartModel->select();

	int quantity = 0;
	float total = 0;
	int index = 0;
	float price = 0;

	QSqlQuery* query = new QSqlQuery;
	query->exec("select * from shoppingCart");

	while(query->next())
	{
		quantity = query->value("quantity").toInt();

		price = query->value("price").toInt();
		total += price * quantity;

		index++;
	}

	ui->tableView_shoppingCart->hideColumn(0);
	ui->tableView_shoppingCart->hideColumn(1);


	ui->tableView_shoppingCart->setModel(cartModel);
	ui->tableView_shoppingCart->setSortingEnabled(true);
	ui->page_adminMainMenu->hide();
	ui->page_shoppingCart->show();
}

void MainWindow::on_lineEdit_password_returnPressed()
{
    on_button_login_clicked();
}


void MainWindow::on_button_chooseTheme_clicked()
{
    // Iterate to next theme index
    currentThemeIndex++;

    // Reset theme index if out of bounds
    if (currentThemeIndex >= themeList.size())
    {
        currentThemeIndex = 0;
    }

    // SET first team image
    QString imgPath = themeList[currentThemeIndex];
    QString styleString = "background-image: url(" + imgPath + ");";
    ui->imageWidget_theme->setStyleSheet(styleString);
    ui->imageWidget_theme->setStyleSheet(styleString);
    ui->imageWidget_theme->update();


}
