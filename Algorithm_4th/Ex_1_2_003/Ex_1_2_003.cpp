#include "Ex_1_2_003.h"
#include <QtGui/QPainter>
#include <random>

using namespace std;

int N = 0;
int min = 0;
int max = 0;

Ex_1_2_003::Ex_1_2_003(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.Btn_IC, SIGNAL(clicked()), this, SLOT(OnClickedBtnIC()));
}

void Ex_1_2_003::paintEvent(QPaintEvent * event)
{
	if (m_bRefresh) {
		QPainter painter(this);

		painter.setPen(QPen(Qt::black, 1));
		m_rects.clear();
		for (int i = 0; i < N; ++i) {
			QRect rect = randomRect();
			m_rects.emplace_back(rect);
			painter.drawRect(rect);
		}

		m_bRefresh = false;
	}
}

QRect Ex_1_2_003::randomRect()
{
	random_device rd;
	mt19937_64 gen(rd());
	uniform_int_distribution<int> distribution(::min, ::max);
	uniform_int_distribution<int> distribution2(100, 300);
	QRect rect(distribution2(gen), distribution2(gen), distribution(gen), distribution(gen));

	return rect;
}

void Ex_1_2_003::ComputeICCount()
{
	m_iContain = 0;
	m_iIntersect = 0;
	if (m_rects.empty())
		return;

	for (auto iter1 = m_rects.begin(); iter1 != m_rects.end() - 1; ++iter1) {
		auto iter1Next = ++iter1;
		--iter1;
		for (auto iter2 = iter1Next; iter2 != m_rects.end(); ++iter2) {
			if (iter1->contains(*iter2)) {
				++m_iContain;
			}
			else if (iter1->intersected(*iter2) != QRect()) {
				++m_iIntersect;
			}
		}
	}
}

void Ex_1_2_003::OnClickedBtnIC()
{
	// 获取输入值
	N = ui.LE_N->text().toInt();
	::min = ui.LE_Min->text().toInt();
	::max = ui.LE_Max->text().toInt();

	// 重绘
	m_bRefresh = true;
	repaint();

	ComputeICCount();
	ui.Lable_Intersacted->setText(QStringLiteral("相交数：") + QString::number(m_iIntersect));
	ui.Lable_Contains->setText(QStringLiteral("包含数：") + QString::number(m_iContain));	
}