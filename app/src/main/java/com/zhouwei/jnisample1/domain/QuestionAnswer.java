package com.zhouwei.jnisample1.domain;

import org.json.JSONArray;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by zhouwei on 2018/1/22.
 */

public class QuestionAnswer {
    public long channelId;
    public List<Comment> comments = new ArrayList<>();

    public static QuestionAnswer parse(String content) {
        try {
            QuestionAnswer question = new QuestionAnswer();
            JSONObject jsonObject = new JSONObject(content);
            question.channelId = jsonObject.optLong("channel_id");

            JSONObject commentJsonObject = jsonObject.getJSONObject("comment");
            JSONArray commentsJsonArray = commentJsonObject.getJSONArray("comment_list");

            for (int i = 0; i < commentsJsonArray.length(); i++) {
                JSONObject commentJSONObject = commentsJsonArray.getJSONObject(i);

                Comment comment = new Comment();
                comment.msgType = commentJSONObject.optInt("msg_type");
                comment.type = commentJSONObject.optString("type");

                Msg msg = new Msg();
                comment.msg = msg;

                JSONObject msgJSONObject = commentJSONObject.getJSONObject("msg");
                msg.canAnswer = msgJSONObject.getBoolean("can_answer");
                msg.timing = msgJSONObject.getInt("timing");
                msg.problemId = msgJSONObject.getInt("problem_id");
                msg.problem = msgJSONObject.getString("problem");

                JSONArray answersJSONArray = msgJSONObject.getJSONArray("answer");
                for (int j = 0; j < answersJSONArray.length(); j++) {
                    JSONObject questionOrAnswerJSONObject = answersJSONArray.getJSONObject(j);
                    QuestionOrAnswer questionOrAnswer = new QuestionOrAnswer();
                    questionOrAnswer.answerId = questionOrAnswerJSONObject.optString("answer_id");
                    questionOrAnswer.answerMsg = questionOrAnswerJSONObject.optString("answer_msg");
                    questionOrAnswer.answerCount = questionOrAnswerJSONObject.optInt("answer_count");
                    msg.questionOrAnswers.add(questionOrAnswer);
                }

                question.comments.add(comment);
            }

            return question;
        } catch (Exception e) {
            e.printStackTrace();
        }

        return null;
    }

    public static class Comment {
        public int msgType;
        public String type;
        public Msg msg;
    }

    public static class Msg {
        public boolean canAnswer;
        public int timing;
        public int problemId;
        public String problem;
        public List<QuestionOrAnswer> questionOrAnswers = new ArrayList();
    }

    public static QuestionOrAnswer parseAnswer(JSONObject questionOrAnswerJSONObject) {
        return null;
    }

    public static class QuestionOrAnswer {
        public String answerMsg;
        public String answerId;
        public int answerCount;
    }
}
